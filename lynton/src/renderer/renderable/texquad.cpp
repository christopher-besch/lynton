#include "texquad.h"

#include "pch.h"

namespace Lynton {

TexQuad::TexQuad(Renderer* renderer, vec3 origin, vec3 virtual_corner)
    : Renderable(renderer, origin),
      m_virtual_corner(virtual_corner),
      m_top_rigth_corner({virtual_corner[0], origin[1], 1}),
      m_bottom_left_corner({origin[0], virtual_corner[1], 1}),
      m_bottom_right_corner(virtual_corner)
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
    vec3 current_virtual_top_left_corner = m_origin;
    int  flip                            = SDL_FLIP_NONE;

    // when the origin is not on the left side anymore
    if(m_origin[0] > m_virtual_corner[0]) {
        current_virtual_top_left_corner[0] = m_virtual_corner[0];
        flip |= SDL_FLIP_HORIZONTAL;
    }
    // when the origin is not on the top side anymore
    if(m_origin[1] > m_virtual_corner[1]) {
        current_virtual_top_left_corner[1] = m_virtual_corner[1];
        flip |= SDL_FLIP_VERTICAL;
    }

    // corner used for sdl renderer
    flip                 = SDL_FLIP_NONE;
    vec3   sdl_corner    = m_origin;
    scalar used_rotation = m_rotation;
    if(m_flip_hor && !m_flip_ver) {
        sdl_corner    = m_top_rigth_corner;
        flip          = SDL_FLIP_HORIZONTAL;
        used_rotation = 360 - used_rotation;
    }
    else if(!m_flip_hor && m_flip_ver) {
        sdl_corner    = m_bottom_left_corner;
        flip          = SDL_FLIP_VERTICAL;
        used_rotation = 360 - used_rotation;
    }
    else if(m_flip_hor && m_flip_ver) {
        sdl_corner = m_bottom_right_corner;
        flip       = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
    }

    scalar width  = std::abs(m_virtual_corner[0] - m_origin[0]);
    scalar height = std::abs(m_virtual_corner[1] - m_origin[1]);

    m_renderer->get_texture_library()->render(m_texture_id,
                                              sdl_corner[0],
                                              sdl_corner[1],
                                              width,
                                              height,
                                              nullptr,
                                              used_rotation,
                                              static_cast<SDL_RendererFlip>(flip));
    vec3 scale = m_virtual_corner - m_origin;
}

/////////////////////
// transformations //
/////////////////////
void TexQuad::set_location(vec3 origin)
{
    // how to move old origin to get to new
    vec3 direction = origin - m_origin;
    translate(direction[0], direction[1]);
}

void TexQuad::translate(scalar dx, scalar dy)
{
    mul_all_mat(trans_mat3(dx, dy));
}

void TexQuad::rotate(scalar angle)
{
    // squares stay squares
    vec3 scale = m_virtual_corner - m_origin;
    mul_mat(rot_mat3(angle));
    m_virtual_corner = m_origin + scale;
    if(m_flip_hor != m_flip_ver)
        m_rotation -= angle;
    else
        m_rotation += angle;
}

void TexQuad::scale(scalar fx, scalar fy)
{
    mul_all_mat(sca_mat3(fx, fy));
    if((fx < 0))
        m_flip_hor = !m_flip_hor;
    if((fy < 0))
        m_flip_ver = !m_flip_ver;
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
    vec3 half_diagonal = (m_virtual_corner - get_top_left()) / 2;
    // when there has been one and only one flip
    if(m_origin[0] > m_virtual_corner[0] != m_origin[1] > m_virtual_corner[1]) {
        half_diagonal = rot_mat3(-m_rotation) * half_diagonal;
    }
    else {
        half_diagonal = rot_mat3(m_rotation) * half_diagonal;
    }

    return m_origin + half_diagonal;
}

} // namespace Lynton
