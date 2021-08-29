#include "texquad.h"

#include "pch.h"

namespace Lynton {

TexQuad::TexQuad(Renderer* renderer, Camera* camera, vec3 top_left, scalar width, scalar height)
    : Renderable(renderer, camera, top_left), m_width(width), m_height(height)
{
    log_lynton_extra("Creating texture quad");
}
TexQuad::~TexQuad()
{
    log_lynton_extra("Deleting texture quad");
}

void TexQuad::render() const
{
    scalar rotation     = m_rotation + m_camera->get_inv_rotation();
    mat3   mat          = m_camera->get_inv_mat() * m_mat;
    vec3   top_left     = get_top_left_mat(mat);
    vec3   top_right    = get_top_right_mat(mat);
    vec3   bottom_left  = get_bottom_left_mat(mat);
    vec3   bottom_right = get_bottom_right_mat(mat);
    scalar width        = arma::norm(top_left - top_right);
    scalar height       = arma::norm(top_left - bottom_left);

    m_renderer->get_texture_library()->render(m_texture_id,
                                              top_left[0],
                                              top_left[1],
                                              width,
                                              height,
                                              nullptr,
                                              rotation,
                                              SDL_FLIP_NONE);
}

vec3 TexQuad::get_middle() const
{
    vec3 top_left     = get_top_left();
    vec3 bottom_right = get_bottom_right();
    // adding half the diagonal
    return top_left + (bottom_right - top_left) / 2;
}

vec3 TexQuad::get_middle_mat(const mat3& mat) const
{
    vec3 top_left     = get_top_left_mat(mat);
    vec3 bottom_right = get_bottom_right_mat(mat);
    // adding half the diagonal
    return top_left + (bottom_right - top_left) / 2;
}

} // namespace Lynton
