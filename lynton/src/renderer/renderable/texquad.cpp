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
    // apply camera
    vec3 cam_origin              = m_camera->get_mat() * m_origin;
    vec3 cam_top_rigth_corner    = m_camera->get_mat() * m_top_right_corner;
    vec3 cam_bottom_left_corner  = m_camera->get_mat() * m_bottom_left_corner;
    vec3 cam_bottom_right_corner = m_camera->get_mat() * m_bottom_right_corner;

    scalar sdl_rotation = m_rotation + m_camera->get_rotation();
    bool   sdl_flip_hor = m_flip_hor != m_camera->get_flip_hor();
    bool   sdl_flip_ver = m_flip_ver != m_camera->get_flip_ver();

    // used for sdl renderer to simulate vertices
    int flip = SDL_FLIP_NONE | sdl_flip_hor * SDL_FLIP_HORIZONTAL | sdl_flip_ver * SDL_FLIP_VERTICAL;

    sdl_rotation = sdl_flip_hor != sdl_flip_ver ? 360 - sdl_rotation : sdl_rotation;

    vec3 sdl_origin = cam_origin;
    // if(sdl_flip_hor && !sdl_flip_ver)
    //     sdl_origin = cam_top_rigth_corner;
    // else if(!sdl_flip_hor && sdl_flip_ver)
    //     sdl_origin = cam_bottom_left_corner;
    // else if(sdl_flip_hor && sdl_flip_ver)
    //     sdl_origin = cam_bottom_right_corner;

    vec3 virtual_diagonal = cam_origin - m_origin;
    // virtual_diagonal        = sca_mat3(1 - 2 * sdl_flip_hor, 1 - 2 * sdl_flip_hor) * virtual_diagonal;
    vec3 sdl_virtual_corner = m_virtual_corner + virtual_diagonal;

    scalar width  = std::abs(sdl_virtual_corner[0] - sdl_origin[0]);
    scalar height = std::abs(sdl_virtual_corner[1] - sdl_origin[1]);
    log_lynton_extra("{} {}", width, height);

    m_renderer->get_texture_library()->render(m_texture_id,
                                              sdl_origin[0],
                                              sdl_origin[1],
                                              width,
                                              height,
                                              nullptr,
                                              sdl_rotation,
                                              static_cast<SDL_RendererFlip>(flip));
}

vec3 TexQuad::get_middle() const
{
    vec3 top_left     = get_top_left();
    vec3 bottom_right = get_bottom_right();
    // adding half the diagonal
    return top_left + (bottom_right - top_left) / 2;
}

} // namespace Lynton
