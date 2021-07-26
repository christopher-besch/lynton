#include "texquad.h"

#include "pch.h"

namespace Lynton {

TexQuad::TexQuad(Renderer* renderer, vec3 origin, vec3 virtual_corner)
    : Renderable(renderer, origin),
      m_top_rigth_corner({virtual_corner[0], origin[1], 1}),
      m_bottom_left_corner({origin[0], virtual_corner[1], 1}),
      m_bottom_right_corner(virtual_corner),
      m_virtual_corner(virtual_corner)
{
    log_lynton_extra("Creating texture quad");
}

TexQuad::TexQuad(Renderer* renderer, vec3 origin, scalar width, scalar height)
    : TexQuad(renderer, origin, origin + vec3 {width, height, 0}) {}

TexQuad::~TexQuad()
{
    log_lynton_extra("Deleting texture quad");
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
    // this step misaligns m_virtual_corner
    m_virtual_corner = m_origin + scale;
    // when only once flipped -> has to be rotated in opposite direction
    if(m_flip_hor != m_flip_ver)
        m_rotation -= angle;
    else
        m_rotation += angle;
}

void TexQuad::scale(scalar fx, scalar fy)
{
    mul_all_mat(sca_mat3(fx, fy));
    if(fx < 0)
        m_flip_hor = !m_flip_hor;
    if(fy < 0)
        m_flip_ver = !m_flip_ver;
}

void TexQuad::render() const
{
    // used for sdl renderer to simulate vertices
    int flip = SDL_FLIP_NONE | m_flip_hor * SDL_FLIP_HORIZONTAL | m_flip_ver * SDL_FLIP_VERTICAL;

    scalar used_rotation = m_flip_hor != m_flip_ver ? 360 - m_rotation : m_rotation;

    vec3 sdl_corner = m_origin;
    if(m_flip_hor && !m_flip_ver) {
        sdl_corner = m_top_rigth_corner;
    }
    else if(!m_flip_hor && m_flip_ver) {
        sdl_corner = m_bottom_left_corner;
    }
    else if(m_flip_hor && m_flip_ver) {
        sdl_corner = m_bottom_right_corner;
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
}

vec3 TexQuad::get_middle() const
{
    vec3 half_diagonal = (m_bottom_right_corner - m_origin) / 2;
    return m_origin + half_diagonal;
}

} // namespace Lynton
