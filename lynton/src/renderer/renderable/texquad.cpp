#include "texquad.h"

#include "pch.h"

namespace Lynton {

TexQuad::TexQuad(Renderer* renderer, Camera* camera, vec3 top_left, scalar width, scalar height)
    : Renderable(renderer, camera)
{
    log_lynton_extra("Creating texture quad");
    scale(width, height);
    translate(top_left);
}

TexQuad::~TexQuad()
{
    log_lynton_extra("Deleting texture quad");
}

void TexQuad::render() const
{
    vec3   top_left     = get_top_left();
    vec3   top_right    = get_top_right();
    vec3   bottom_left  = get_bottom_left();
    vec3   bottom_right = get_bottom_right();
    scalar width        = arma::norm(top_left - top_right);
    scalar height       = arma::norm(top_left - bottom_left);
    // log_lynton_extra("{}", m_rotation);

    m_renderer->get_texture_library()->render(m_texture_id,
                                              top_left[0],
                                              top_left[1],
                                              width,
                                              height,
                                              nullptr,
                                              m_rotation,
                                              SDL_FLIP_NONE);
}

vec3 TexQuad::get_middle() const
{
    vec3 top_left     = get_top_left();
    vec3 bottom_right = get_bottom_right();
    // adding half the diagonal
    return top_left + (bottom_right - top_left) / 2;
}

} // namespace Lynton
