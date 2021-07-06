#pragma once

#include <SDL.h>

namespace Lynton {
class Renderable {
public:
    virtual ~Renderable();

    virtual void set_color(uint8_t r, uint8_t g, uint8_t b) = 0;
    virtual void set_blend_mode(SDL_BlendMode blend)        = 0;
    virtual void set_alpha(uint8_t a)                       = 0;

    virtual void render(SDL_Renderer* sdl_renderer, int x, int y) = 0;
};
} // namespace Lynton
