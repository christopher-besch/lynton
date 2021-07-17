#pragma once

#include "core/random.h"
#include "renderer/texture/texture_library.h"

#include <SDL.h>
#include <string>

namespace Lynton {
class Renderer {
public:
    Renderer(const std::string& name, int screen_width, int screen_height, RandomGen* random_gen);

    ~Renderer();

    // clear screen
    void clear();

    void set_viewport(int x, int y, int w, int h);

    // actually draw to screen
    void update();

private:
    std::string    m_name;
    int            m_screen_width;
    int            m_screen_height;
    SDL_Window*    m_window       = nullptr;
    SDL_Renderer*  m_sdl_renderer = nullptr;
    RandomGen*     m_random_gen   = nullptr;
    TextureLibrary m_texture_library;
};
} // namespace Lynton
