#include "texquad.h"

#include "pch.h"

namespace Lynton {

TexQuad::TexQuad(Renderer* renderer, vec3 origin, vec3 other_corner)
    : Renderable(renderer, origin), m_other_corner(other_corner), m_rotation(0)
{
    log_lynton_extra("Creating texture quad");
}

TexQuad::TexQuad(Renderer* renderer, vec3 origin, scalar width, scalar height)
    : TexQuad(renderer, origin, {origin[0] + width, origin[1] + height, 1}) {}

TexQuad::~TexQuad()
{
    log_lynton_extra("Deleting texture quad");
}

void TexQuad::render() const
{
    // todo: may not be branchless
    // todo: sub coordinates missing <- sprite sheets
    vec3 top_right_corner = m_origin;
    int  flip             = SDL_FLIP_NONE;

    // when the origin is not on the left side
    if(m_origin[0] > m_other_corner[0]) {
        top_right_corner[0] = m_other_corner[0];
        flip |= SDL_FLIP_HORIZONTAL;
    }
    // when the origin is not on the top side
    if(m_origin[1] > m_other_corner[1]) {
        top_right_corner[1] = m_other_corner[1];
        flip |= SDL_FLIP_VERTICAL;
    }

    scalar width  = std::abs(m_origin[0] - m_other_corner[0]);
    scalar height = std::abs(m_origin[1] - m_other_corner[1]);

    m_renderer->get_texture_library()->render(m_texture_id, top_right_corner[0], top_right_corner[1], width, height, nullptr, m_rotation, static_cast<SDL_RendererFlip>(flip));
    vec3 scale = m_other_corner - m_origin;
}

/////////////////////
// transformations //
/////////////////////
void TexQuad::set_location(vec3 origin)
{
    vec3 diagonal  = m_other_corner - m_origin;
    m_origin       = origin;
    m_other_corner = origin + diagonal;
}

void TexQuad::translate(scalar dx, scalar dy)
{
    m_origin       = trans_mat3(dx, dy) * m_origin;
    m_other_corner = trans_mat3(dx, dy) * m_other_corner;
}

void TexQuad::rotate(scalar angle)
{
    // squares stay squares
    vec3 scale     = m_other_corner - m_origin;
    m_origin       = rot_mat3(angle) * m_origin;
    m_other_corner = m_origin + scale;
    m_rotation += angle;
}

void TexQuad::scale(scalar fx, scalar fy)
{
    m_origin       = ska_mat3(fx, fy) * m_origin;
    m_other_corner = ska_mat3(fx, fy) * m_other_corner;
}

//////////////////////////////
// transformations at pivot //
//////////////////////////////
void TexQuad::rotate_at(scalar angle, vec3 pivot)
{
    translate(-pivot);
    rotate(angle);
    translate(pivot);
}

// doesn't support prior rotation
void TexQuad::scale_at(scalar fx, scalar fy, vec3 pivot)
{
    translate(-pivot);
    scale(fx, fy);
    translate(pivot);
}

void TexQuad::flip_hor_at(vec3 pivot)
{
    translate(-pivot);
    flip_hor();
    translate(pivot);
}

void TexQuad::flip_ver_at(vec3 pivot)
{
    translate(-pivot);
    flip_ver();
    translate(pivot);
}

vec3 TexQuad::get_middle() const
{
    vec3 half_diagonal         = (m_other_corner - m_origin) / 2;
    vec3 rotated_half_diagonal = rot_mat3(m_rotation) * half_diagonal;

    return m_origin + rotated_half_diagonal;
}

} // namespace Lynton
