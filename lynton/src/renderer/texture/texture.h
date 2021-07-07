#pragma once

#include <SDL.h>
#include <string>

namespace Lynton {
class Texture {
public:
    ~Texture() { free(); }

    void free();

    bool load_from_file(const std::string& path);
    bool load_from_text(const std::string& text, SDL_Color text_color);
    bool create_blank(int widht, int height, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);

    void set_color(uint8_t r, uint8_t g, uint8_t b);
    void set_blend_mode(SDL_BlendMode mode);
    void set_alpha(uint8_t a);

    int w() { return m_width; }
    int h() { return m_height; }

private:
    SDL_Texture* m_texture = nullptr;
    int          m_width   = 0;
    int          m_height  = 0;
};
} // namespace Lynton
