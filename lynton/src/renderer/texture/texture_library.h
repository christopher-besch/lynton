#pragma once

#include "core/random.h"
#include "renderer/texture/font.h"

#include <SDL.h>
#include <unordered_map>

namespace Lynton {
struct Texture {
    SDL_Renderer* renderer = nullptr;
    // hardware texture
    SDL_Texture* texture = nullptr;
    // not nullptr when texture locked
    void* pixels = nullptr;
    // amount of bytes per line in texture -> width of texture in memory
    int pitch = 0;
    // dimensions
    int width  = 0;
    int height = 0;
};

class TextureLibrary {
public:
    TextureLibrary(SDL_Renderer* renderer, RandomGen* random_gen);
    ~TextureLibrary();

    // create new texture
    // return id
    // return 0 if failed
    unsigned short load_from_file(const std::string& path, SDL_TextureAccess access = SDL_TEXTUREACCESS_STREAMING);
    unsigned short load_from_text(const std::string& text, SDL_Color text_color, Font& font);
    unsigned short create_blank(int width, int height, SDL_TextureAccess access = SDL_TEXTUREACCESS_STREAMING);

    // deallocate texture
    void free(unsigned short id);
    void free_all();

    // check if texture with specified id is existent
    bool is_used(unsigned short id)
    {
        return m_textures.count(id);
    }

    // modulate texture rgb
    void set_color(unsigned short id, uint8_t r, uint8_t g, uint8_t b);
    void set_blend_mode(unsigned short id, SDL_BlendMode mode);
    // modulate texture alpha
    void set_alpha(unsigned short id, uint8_t a);

    // clip == nullptr -> render clip from sprite sheet
    void render(unsigned short id, int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // pixel manipulators
    bool     lock(unsigned short id);
    bool     unlock(unsigned short id);
    void     copyPixels(unsigned short id, void* pixels);
    uint32_t get_pixel32(unsigned short id, unsigned int x, unsigned int y);

    void* get_pixels(unsigned short id);
    int   get_pitch(unsigned short id);

    int get_width(unsigned short id);
    int get_height(unsigned short id);

private:
    // returns id of create texture
    Texture* add_texture(unsigned short& id);
    Texture* get_texture(unsigned short id);

private:
    SDL_Renderer*                               m_renderer   = nullptr;
    RandomGen*                                  m_random_gen = nullptr;
    std::unordered_map<unsigned short, Texture> m_textures;
};
} // namespace Lynton
