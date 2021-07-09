#pragma once

#include <SDL.h>
#include <string>

namespace Lynton {
class Texture {
public:
    Texture(SDL_Renderer* renderer)
        : m_renderer(renderer) {}

    ~Texture() { free(); }

    void free();

    bool load_from_file(const std::string& path, SDL_TextureAccess access = SDL_TEXTUREACCESS_STREAMING);
    bool load_from_text(const std::string& text, SDL_Color text_color, SDL_TextureAccess access = SDL_TEXTUREACCESS_STREAMING);
    bool create_blank(int widht, int height, SDL_TextureAccess access = SDL_TEXTUREACCESS_STREAMING);

    void set_color(uint8_t r, uint8_t g, uint8_t b);
    void set_blend_mode(SDL_BlendMode mode);
    void set_alpha(uint8_t a);

    int w() { return m_width; }
    int h() { return m_height; }

private:
    SDL_Renderer* m_renderer = nullptr;
    SDL_Texture*  m_texture  = nullptr;
    int           m_width    = 0;
    int           m_height   = 0;
};
} // namespace Lynton
