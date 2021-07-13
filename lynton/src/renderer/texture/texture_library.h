#pragma once

#include <SDL.h>
#include <unordered_map>

namespace Lynton {
struct Texture {
    SDL_Renderer* m_renderer = nullptr;
    // hardware texture
    SDL_Texture* m_texture = nullptr;
    // not nullptr when texture locked
    void* m_pixels = nullptr;
    // amount of bytes per line in texture -> width of texture in memory
    int m_pitch;
    // dimensions
    int m_width  = 0;
    int m_height = 0;
};

class TextureLibrary {
public:
    TextureLibrary(SDL_Renderer* renderer)
        : m_renderer(renderer) {}
    ~TextureLibrary() { free_all_textures(); }

    // returns id of create texture
    int add_texture();
    // cleanly delete texture with id
    void free_texture(int id);
    void free_all_textures();

private:
    SDL_Renderer*                               m_renderer = nullptr;
    std::unordered_map<unsigned short, Texture> m_textures;
};
} // namespace Lynton
