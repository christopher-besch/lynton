#include "renderer.h"

#include "pch.h"

namespace Lynton {
Renderer::Renderer(const std::string& name, int screen_width, int screen_height)
{
    SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
}
} // namespace Lynton
