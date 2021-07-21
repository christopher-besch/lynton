#pragma once

#include "renderer/renderer.h"

#include <SDL.h>

namespace Lynton {
class Renderable {
public:
    Renderable(Renderer* renderer, vec3 origin)
        : m_renderer(renderer), m_origin(origin) {}
    virtual ~Renderable() = default;

    // certain limitations in the use of these methods may be set by inheriting classes
    virtual void translate(scalar dx, scalar dy) = 0;
    virtual void rotate(scalar angle)            = 0;
    virtual void scale(scalar dx, scalar dy)     = 0;
    virtual void mirror_hor()                    = 0;
    virtual void mirror_ver()                    = 0;

    virtual void render() = 0;

    vec3 get_origin() { return m_origin; }

protected:
    Renderer* m_renderer = nullptr;
    vec3      m_origin;
};
} // namespace Lynton
