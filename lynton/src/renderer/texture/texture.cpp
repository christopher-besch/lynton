#include "texture.h"

#include "pch.h"

namespace Lynton {

void Texture::free()
{
    if(m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
        m_width   = 0;
        m_height  = 0;
        m_pixels  = nullptr;
        m_pitch   = 0;
    }
}

bool Texture::load_from_file(const std::string& path, SDL_TextureAccess access)
{
    // remove preexisting texture
    free();

    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == nullptr) {
        log_lynton_error("Unable to load image '{}'! SDL_image Error: {}", path, IMG_GetError());
        return false;
    }
    // convert surface to display format
    SDL_Surface* formatted_surface = SDL_ConvertSurfaceFormat(loaded_surface, SDL_PIXELFORMAT_RGBA8888, 0);
    // not needed anymore
    SDL_FreeSurface(loaded_surface);
    if(formatted_surface == nullptr) {
        log_lynton_error("Unable to convert loaded surface from '{}' to display format! SDL_image Error: {}", path, IMG_GetError());
        return false;
    }
    // create blank texture
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, access, formatted_surface->w, formatted_surface->h);
    if(m_texture == nullptr) {
        log_lynton_error("Unable to create blank texture for '{}'! SDL_image Error: {}", path, IMG_GetError());
        SDL_FreeSurface(formatted_surface);
        return false;
    }

    // lock texture for manipulation
    SDL_LockTexture(m_texture, nullptr, &m_pixels, &m_pitch);

    // copy loaded/formatted surface pixels
    memcpy(m_pixels, formatted_surface->pixels, formatted_surface->pitch * formatted_surface->h);

    // unlock texture to update
    SDL_UnlockTexture(m_texture);
    m_pixels = nullptr;

    m_width  = formatted_surface->w;
    m_height = formatted_surface->h;

    // free formatted surface
    SDL_FreeSurface(formatted_surface);

    return true;
}

bool Texture::load_from_text(const std::string& text, SDL_Color text_color, Font& font, SDL_TextureAccess access)
{
    // remove preexisting texture
    free();

    // render text surface
    SDL_Surface* text_surface = TTF_RenderText_Solid(font.get_font(), text.c_str(), text_color);
    if(text_surface == nullptr) {
        log_lynton_error("Unable to render text '{}'! SDL_ttf Error: {}", text, TTF_GetError());
        return false;
    }
    m_texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);
    SDL_FreeSurface(text_surface);
    if(m_texture == nullptr) {
        log_lynton_error("Unable to create texture form renderer text '{}'! SDL Error: {}", text, SDL_GetError());
        return false;
    }
    m_width  = text_surface->w;
    m_height = text_surface->h;

    return true;
}

bool Texture::create_blank(int width, int height, SDL_TextureAccess access)
{
    // create blank texture
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, access, width, height);
    if(m_texture == nullptr) {
        log_lynton_error("Unable to create blank texture! SDL_ttf Error: {}", IMG_GetError());
        return false;
    }
    m_width  = width;
    m_height = height;

    return true;
}

void Texture::set_color(uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetTextureColorMod(m_texture, r, g, b);
}

void Texture::set_blend_mode(SDL_BlendMode mode)
{
    SDL_SetTextureBlendMode(m_texture, mode);
}

void Texture::set_alpha(uint8_t a)
{
    SDL_SetTextureAlphaMod(m_texture, a);
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect render_quad = {x, y, m_width, m_height};
    if(clip != nullptr) {
        render_quad.w = clip->w;
        render_quad.h = clip->h;
    }
    SDL_RenderCopyEx(m_renderer, m_texture, clip, &render_quad, angle, center, flip);
}

bool Texture::lock()
{
    if(m_pixels != nullptr) {
        log_lynton_error("Texture is already locked!");
        return false;
    }
    // store pixels and pitch in object
    if(!SDL_LockTexture(m_texture, nullptr, &m_pixels, &m_pitch)) {
        log_lynton_error("Unable to lock texture! SDL error: {}", SDL_GetError());
        return false;
    }
    return true;
}

bool Texture::unlock()
{
    if(m_pixels == nullptr) {
        log_lynton_error("Texture is not locked!");
        return false;
    }
    SDL_UnlockTexture(m_texture);
    m_pixels = nullptr;
    m_pitch  = 0;
    return true;
}

void Texture::copyPixels(void* pixels)
{
    if(m_pixels != nullptr)
        // copy to locked pixels
        memcpy(m_pixels, pixels, m_pitch * m_height);
}

uint32_t Texture::get_pixel32(unsigned int x, unsigned int y)
{
    uint32_t* pixels = static_cast<uint32_t*>(m_pixels);
    // get requested pixel
    return pixels[y * (m_pitch / 4) + x];
}

} // namespace Lynton
