#pragma once

#include "renderer/renderer.h"

#include <SDL.h>

namespace Lynton {
class Renderable {
public:
    virtual ~Renderable();

private:
    virtual void render(SDL_Renderer* sdl_renderer, int x, int y) = 0;

private:
    Renderer* m_renderer = nullptr;
    int       x, y;
    int       w, h;
};
} // namespace Lynton
