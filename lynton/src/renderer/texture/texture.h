#pragma once

#include "renderer/texture/font.h"

#include <SDL.h>
#include <string>

namespace Lynton {
class Texture {
private:
    Texture(SDL_Renderer* renderer)
        : m_renderer(renderer) {}

public:
    ~Texture() { free(); }

    bool load_from_file(const std::string& path, SDL_TextureAccess access = SDL_TEXTUREACCESS_STREAMING);
    bool load_from_text(const std::string& text, SDL_Color text_color, Font& font, SDL_TextureAccess access = SDL_TEXTUREACCESS_STREAMING);
    bool create_blank(int width, int height, SDL_TextureAccess access = SDL_TEXTUREACCESS_STREAMING);

    // deallocate texture
    void free();

    // modulate texture rgb
    void set_color(uint8_t r, uint8_t g, uint8_t b);
    void set_blend_mode(SDL_BlendMode mode);
    // modulate texture alpha
    void set_alpha(uint8_t a);

    // clip == nullptr -> render clip from sprite sheet
    void render(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // pixel manipulators
    bool     lock();
    bool     unlock();
    void     copyPixels(void* pixels);
    uint32_t get_pixel32(unsigned int x, unsigned int y);

    void* get_pixels() { return m_pixels; }
    int   get_pitch() { return m_pitch; }

    int w() { return m_width; }
    int h() { return m_height; }

private:
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
} // namespace Lynton
