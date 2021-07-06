#pragma once

#include "renderable.h"

#include <SDL.h>
#include <string>

namespace Lynton {
class Renderer {
public:
    Renderer(const std::string& name, int screen_width, int screen_height);

    ~Renderer();

    // clear screen
    void clear();

    void set_viewport(int x, int y, int w, int h);

    void render(Renderable* renderable, int x, int y) { renderable->render(m_sdl_renderer, x, y); }

    // actually draw to screen
    void update();

private:
    std::string   m_name;
    int           m_screen_width;
    int           m_screen_height;
    SDL_Window*   m_window       = nullptr;
    SDL_Renderer* m_sdl_renderer = nullptr;
};
} // namespace Lynton
