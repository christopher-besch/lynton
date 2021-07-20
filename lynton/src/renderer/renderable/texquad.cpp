#include "texquad.h"

#include "pch.h"

namespace Lynton {
TexQuad::TexQuad(Renderer* renderer, arma::vec3 origin, arma::vec3 scale)
    : Renderable(renderer, origin), m_scale(scale)
{
    log_lynton_extra("Creating texture quad");
}

TexQuad::~TexQuad()
{
    log_lynton_extra("Deleting texture quad");
}

void TexQuad::render()
{
    // todo: sub coordinates missing <- sprite sheets
    m_renderer->get_texture_library()->render(m_texture_id, m_origin, m_scale);
}
} // namespace Lynton
