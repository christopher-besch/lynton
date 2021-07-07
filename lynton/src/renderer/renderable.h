#pragma once

#include <SDL.h>

namespace Lynton {
class Renderable {
public:
    virtual ~Renderable();

private:
    virtual void render(SDL_Renderer* sdl_renderer, int x, int y) = 0;
};
} // namespace Lynton
