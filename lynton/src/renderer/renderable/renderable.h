#pragma once

#include "renderer/renderer.h"

#include <SDL.h>
#include <armadillo>

namespace Lynton {
class Renderable {
public:
    Renderable(Renderer* renderer, arma::vec3 origin)
        : m_renderer(renderer), m_origin(origin) {}
    virtual ~Renderable() = default;

    virtual void render() = 0;

    // add rotation, translation, scale

    arma::vec3 get_origin() { return m_origin; }

protected:
    Renderer*  m_renderer = nullptr;
    arma::vec3 m_origin;
};
} // namespace Lynton
