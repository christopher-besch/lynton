#pragma once

#include <SDL.h>
#include <string>

namespace Lynton {
class Renderer {
public:
    Renderer(const std::string& name, int screen_width, int screen_height);

    ~Renderer();

    void clear();
    void update();

private:
    std::string   m_name;
    int           m_screen_width;
    int           m_screen_height;
    SDL_Window*   m_window       = nullptr;
    SDL_Renderer* m_sdl_renderer = nullptr;
};
} // namespace Lynton
