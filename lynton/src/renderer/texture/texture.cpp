#include "texture.h"

#include "pch.h"

namespace Lynton {
bool Texture::load_from_file(const std::string& path, SDL_TextureAccess access)
{
    // remove preexisting texture
    free();

    SDL_Texture* new_texture = nullptr;

    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == nullptr) {
        log_lynton_error("Unable to load image '{}'! SDL_image Error: {}", path, IMG_GetError());
        return false;
    }
    // convert surface to display format
    SDL_Surface* formatted_surface = SDL_ConvertSurfaceFormat(loaded_surface, SDL_PIXELFORMAT_RGBA8888, 0);
    if(formatted_surface == nullptr) {
        log_lynton_error("Unable to convert loaded surface from '{}' to display format! SDL_image Error: {}", path, IMG_GetError());
        return false;
    }
    // create blank texture
    new_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, access, formatted_surface->w, formatted_surface->h);
    if(new_texture == nullptr) {
        log_lynton_error("Unable to create blank texture for '{}'! SDL_image Error: {}", path, IMG_GetError());
        return false;
    }

    SDL_SetTextureBlendMode(new_texture, SDL_BLENDMODE_BLEND);
    // SDL_LockTexutre(new_texture, &formatted_surface->clip-rect, &m_pixels

    return true;
}
} // namespace Lynton
