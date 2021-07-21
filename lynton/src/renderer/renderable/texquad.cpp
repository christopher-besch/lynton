#include "texquad.h"

#include "pch.h"

namespace Lynton {
TexQuad::TexQuad(Renderer* renderer, vec3 origin, vec3 scale)
    : Renderable(renderer, origin), m_scale(scale), m_rotation(0)
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
    m_renderer->get_texture_library()->render(m_texture_id, m_origin, m_scale, nullptr, m_rotation);
}

void TexQuad::translate(scalar dx, scalar dy)
{
    // only move origin
    m_origin = trans_mat3(dx, dy) * m_origin;
}

void TexQuad::rotate(scalar angle)
{
    // move origin
    m_origin = rot_mat3(angle) * m_origin;
    m_rotation += angle;
}

void TexQuad::scale(scalar dx, scalar dy) {}

void TexQuad::mirror_hor() {}

void TexQuad::mirror_ver() {}

} // namespace Lynton
