#pragma once

#include "renderer/renderer.h"

#include <SDL.h>

namespace Lynton {
class Renderable {
public:
    Renderable(Renderer* renderer, int x, int y, int w, int h)
        : m_renderer(renderer), m_x(x), m_y(y), m_w(w), m_h(h) {}
    virtual ~Renderable() = default;

    virtual void render() = 0;

    void set_location(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    // todo: use matrices instead
    void set_scale(int w, int h)
    {
        m_w = w;
        m_h = h;
    }

    int get_x() { return m_x; }
    int get_y() { return m_y; }
    int get_w() { return m_w; }
    int get_h() { return m_h; }

private:
    virtual void render(SDL_Renderer* sdl_renderer, int x, int y) = 0;

private:
    Renderer* m_renderer = nullptr;
    int       m_x, m_y;
    int       m_w, m_h;
};
} // namespace Lynton
