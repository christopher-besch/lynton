#include "texquad.h"

#include "pch.h"

namespace Lynton {
TexQuad::TexQuad(Renderer* renderer, int x, int y, int w, int h)
    : Renderable(renderer, x, y, w, h)
{
    log_lynton_extra("Creating texture quad");
}

void TexQuad::render()
{
    // todo: sub coordinates missing <- sprite sheets
    m_renderer->get_texture_library()->render(m_texture_id, m_x, m_y, m_w, m_h);
}
} // namespace Lynton
