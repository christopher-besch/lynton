#include "texture.h"

#include "pch.h"

namespace Lynton {
bool Texture::load_from_file(const std::string& path)
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
        log_lynton_error("Unable to convert loaded surfaace from '{}' to display format! SDL_image Error: {}", path, IMG_GetError());
        return false;
    }
    // new_texutre = SDL_CreateTexuter(, SDL

    return true;
}
} // namespace Lynton
