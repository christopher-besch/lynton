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
    Texture*       tex = add_texture(id);

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
    tex->texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, access, formatted_surface->w, formatted_surface->h);
    if(tex->texture == nullptr) {
        log_lynton_error("Unable to create blank texture for '{}'! SDL_image Error: {}", path, IMG_GetError());
        SDL_FreeSurface(formatted_surface);
        free(id);
        return false;
    }

    // lock texture for manipulation
    SDL_LockTexture(tex->texture, nullptr, &tex->pixels, &tex->pitch);

    // copy loaded/formatted surface pixels
    memcpy(tex->pixels, formatted_surface->pixels, formatted_surface->pitch * formatted_surface->h);

    // unlock texture to update
    SDL_UnlockTexture(tex->texture);
    tex->pixels = nullptr;

    tex->width  = formatted_surface->w;
    tex->height = formatted_surface->h;

    // free formatted surface
    SDL_FreeSurface(formatted_surface);

    return id;
}

unsigned short TextureLibrary::load_from_text(const std::string& text, SDL_Color text_color, Font* font)
{
    unsigned short id;
    Texture*       tex = add_texture(id);

    // render text surface
    SDL_Surface* text_surface = TTF_RenderText_Solid(font->get_font(), text.c_str(), text_color);
    if(text_surface == nullptr) {
        log_lynton_error("Unable to render text '{}'! SDL_ttf Error: {}", text, TTF_GetError());
        free(id);
        return false;
    }
    tex->texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);
    SDL_FreeSurface(text_surface);
    if(tex->texture == nullptr) {
        log_lynton_error("Unable to create texture form renderer text '{}'! SDL Error: {}", text, SDL_GetError());
        free(id);
        return false;
    }
    tex->width  = text_surface->w;
    tex->height = text_surface->h;

    return id;
}

unsigned short TextureLibrary::create_blank(int width, int height, SDL_TextureAccess access)
{
    unsigned short id;
    Texture*       tex = add_texture(id);
    // create blank texture
    tex->texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, access, width, height);
    if(tex->texture == nullptr) {
        log_lynton_error("Unable to create blank texture! SDL_ttf Error: {}", IMG_GetError());
        free(id);
        return false;
    }
    tex->width  = width;
    tex->height = height;

    return id;
}

void TextureLibrary::free(unsigned short id)
{
    Texture* tex = get_texture(id);
    if(tex->texture != nullptr)
        SDL_DestroyTexture(tex->texture);
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
    Texture* tex = get_texture(id);
    SDL_SetTextureColorMod(tex->texture, r, g, b);
}

void TextureLibrary::set_blend_mode(unsigned short id, SDL_BlendMode mode)
{
    Texture* tex = get_texture(id);
    SDL_SetTextureBlendMode(tex->texture, mode);
}

void TextureLibrary::set_alpha(unsigned short id, uint8_t a)
{
    Texture* tex = get_texture(id);
    SDL_SetTextureAlphaMod(tex->texture, a);
}

void TextureLibrary::render(unsigned short id, vec3 origin, vec3 scale, SDL_Rect* clip, scalar angle, SDL_Point* center, SDL_RendererFlip flip)
{
    Texture* tex         = get_texture(id);
    SDL_Rect render_quad = {static_cast<int>(origin[0]), static_cast<int>(origin[1]), static_cast<int>(scale[0]), static_cast<int>(scale[1])};
    // if(clip != nullptr) {
    //     render_quad.w = clip->w;
    //     render_quad.h = clip->h;
    // }
    SDL_RenderCopyEx(m_renderer, tex->texture, clip, &render_quad, angle, center, flip);
}

bool TextureLibrary::lock(unsigned short id)
{
    Texture* tex = get_texture(id);
    if(tex->pixels != nullptr) {
        log_lynton_error("Texture '{}' is already locked!", id);
        return false;
    }
    // store pixels and pitch in object
    if(SDL_LockTexture(tex->texture, nullptr, &tex->pixels, &tex->pitch)) {
        log_lynton_error("Unable to lock texture '{}'! SDL error: {}", id, SDL_GetError());
        return false;
    }
    return true;
}

bool TextureLibrary::unlock(unsigned short id)
{
    Texture* tex = get_texture(id);
    if(tex->pixels == nullptr) {
        log_lynton_error("Texture '{}' is not locked!", id);
        return false;
    }
    SDL_UnlockTexture(tex->texture);
    tex->pixels = nullptr;
    tex->pitch  = 0;
    return true;
}

void TextureLibrary::copyPixels(unsigned short id, void* pixels)
{
    Texture* tex = get_texture(id);
    if(tex->pixels != nullptr)
        // copy to locked pixels
        memcpy(tex->pixels, pixels, tex->pitch * tex->height);
    else
        log_lynton_error("Trying to copy pixels to not yet locked texture with id: {}", id);
}

uint32_t TextureLibrary::get_pixel32(unsigned short id, unsigned int x, unsigned int y)
{
    Texture*  tex    = get_texture(id);
    uint32_t* pixels = static_cast<uint32_t*>(tex->pixels);
    // get requested pixel
    return pixels[y * (tex->pitch / 4) + x];
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
