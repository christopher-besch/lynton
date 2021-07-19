#include "texture_library.h"

#include "pch.h"

namespace Lynton {

TextureLibrary::TextureLibrary(SDL_Renderer* renderer, RandomGen* random_gen)
    : m_renderer(renderer), m_random_gen(random_gen)
{
    log_lynton_general("Creating texture library");
}

TextureLibrary::~TextureLibrary()
{
    log_lynton_general("Deleting texture library");
    free_all();
}

unsigned short TextureLibrary::load_from_file(const std::string& path, SDL_TextureAccess access)
{
    unsigned short id;
    Texture*       texture = add_texture(id);

    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == nullptr) {
        log_lynton_error("Unable to load image '{}'! SDL_image Error: {}", path, IMG_GetError());
        free(id);
        return false;
    }
    // convert surface to display format
    SDL_Surface* formatted_surface = SDL_ConvertSurfaceFormat(loaded_surface, SDL_PIXELFORMAT_RGBA8888, 0);
    // not needed anymore
    SDL_FreeSurface(loaded_surface);
    if(formatted_surface == nullptr) {
        log_lynton_error("Unable to convert loaded surface from '{}' to display format! SDL_image Error: {}", path, IMG_GetError());
        free(id);
        return false;
    }
    // create blank texture
    texture->texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, access, formatted_surface->w, formatted_surface->h);
    if(texture->texture == nullptr) {
        log_lynton_error("Unable to create blank texture for '{}'! SDL_image Error: {}", path, IMG_GetError());
        SDL_FreeSurface(formatted_surface);
        free(id);
        return false;
    }

    // lock texture for manipulation
    SDL_LockTexture(texture->texture, nullptr, &texture->pixels, &texture->pitch);

    // copy loaded/formatted surface pixels
    memcpy(texture->pixels, formatted_surface->pixels, formatted_surface->pitch * formatted_surface->h);

    // unlock texture to update
    SDL_UnlockTexture(texture->texture);
    texture->pixels = nullptr;

    texture->width  = formatted_surface->w;
    texture->height = formatted_surface->h;

    // free formatted surface
    SDL_FreeSurface(formatted_surface);

    return id;
}

unsigned short TextureLibrary::load_from_text(const std::string& text, SDL_Color text_color, Font& font)
{
    unsigned short id;
    Texture*       texture = add_texture(id);

    // render text surface
    SDL_Surface* text_surface = TTF_RenderText_Solid(font.get_font(), text.c_str(), text_color);
    if(text_surface == nullptr) {
        log_lynton_error("Unable to render text '{}'! SDL_ttf Error: {}", text, TTF_GetError());
        free(id);
        return false;
    }
    texture->texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);
    SDL_FreeSurface(text_surface);
    if(texture->texture == nullptr) {
        log_lynton_error("Unable to create texture form renderer text '{}'! SDL Error: {}", text, SDL_GetError());
        free(id);
        return false;
    }
    texture->width  = text_surface->w;
    texture->height = text_surface->h;

    return id;
}

unsigned short TextureLibrary::create_blank(int width, int height, SDL_TextureAccess access)
{
    unsigned short id;
    Texture*       texture = add_texture(id);
    // create blank texture
    texture->texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, access, width, height);
    if(texture->texture == nullptr) {
        log_lynton_error("Unable to create blank texture! SDL_ttf Error: {}", IMG_GetError());
        free(id);
        return false;
    }
    texture->width  = width;
    texture->height = height;

    return id;
}

void TextureLibrary::free(unsigned short id)
{
    Texture* texture = get_texture(id);
    if(texture->texture != nullptr)
        SDL_DestroyTexture(texture->texture);
    log_lynton_extra("Deleting texture with id: {}", id);
    m_textures.erase(id);
}

void TextureLibrary::free_all()
{
    log_lynton_extra("Clearing all textures");
    // delete until empty
    while(!m_textures.empty())
        free(m_textures.begin()->first);
}

void TextureLibrary::set_color(unsigned short id, uint8_t r, uint8_t g, uint8_t b)
{
    Texture* texture = get_texture(id);
    SDL_SetTextureColorMod(texture->texture, r, g, b);
}

void TextureLibrary::set_blend_mode(unsigned short id, SDL_BlendMode mode)
{
    Texture* texture = get_texture(id);
    SDL_SetTextureBlendMode(texture->texture, mode);
}

void TextureLibrary::set_alpha(unsigned short id, uint8_t a)
{
    Texture* texture = get_texture(id);
    SDL_SetTextureAlphaMod(texture->texture, a);
}

void TextureLibrary::render(unsigned short id, int x, int y, int w, int h, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    Texture* texture     = get_texture(id);
    SDL_Rect render_quad = {x, y, w, h};
    // if(clip != nullptr) {
    //     render_quad.w = clip->w;
    //     render_quad.h = clip->h;
    // }
    SDL_RenderCopyEx(m_renderer, texture->texture, clip, &render_quad, angle, center, flip);
}

bool TextureLibrary::lock(unsigned short id)
{
    Texture* texture = get_texture(id);
    if(texture->pixels != nullptr) {
        log_lynton_error("Texture '{}' is already locked!", id);
        return false;
    }
    // store pixels and pitch in object
    if(!SDL_LockTexture(texture->texture, nullptr, &texture->pixels, &texture->pitch)) {
        log_lynton_error("Unable to lock texture '{}'! SDL error: {}", id, SDL_GetError());
        return false;
    }
    return true;
}

bool TextureLibrary::unlock(unsigned short id)
{
    Texture* texture = get_texture(id);
    if(texture->pixels == nullptr) {
        log_lynton_error("Texture '{}' is not locked!", id);
        return false;
    }
    SDL_UnlockTexture(texture->texture);
    texture->pixels = nullptr;
    texture->pitch  = 0;
    return true;
}

void TextureLibrary::copyPixels(unsigned short id, void* pixels)
{
    Texture* texture = get_texture(id);
    if(texture->pixels != nullptr)
        // copy to locked pixels
        memcpy(texture->pixels, pixels, texture->pitch * texture->height);
    else
        log_lynton_error("Trying to copy pixels to not yet locked texture with id: {}", id);
}

uint32_t TextureLibrary::get_pixel32(unsigned short id, unsigned int x, unsigned int y)
{
    Texture*  texture = get_texture(id);
    uint32_t* pixels  = static_cast<uint32_t*>(texture->pixels);
    // get requested pixel
    return pixels[y * (texture->pitch / 4) + x];
}

/////////////
// private //
/////////////
Texture* TextureLibrary::add_texture(unsigned short& id)
{
    // get first unused id
    // id = 0 is not allowed <- used as error code
    do {
        id = m_random_gen->next_unsigned_short();
    } while(!id || is_used(id));
    log_lynton_extra("Creating texture with id: {}", id);
    // create texture at id
    m_textures.emplace(id, Texture {m_renderer});
    return &m_textures[id];
}

Texture* TextureLibrary::get_texture(unsigned short id)
{
    if(!is_used(id)) {
        raise_critical("Accessing texture with invalid id: {}", id);
        return nullptr;
    }
    return &m_textures[id];
}

} // namespace Lynton
