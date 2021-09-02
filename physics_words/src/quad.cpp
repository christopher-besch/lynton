#include "quad.h"

#include <cmath>

Quad::Quad(Lynton::Renderer* renderer, Lynton::Camera* camera, Lynton::vec3 pos, Lynton::scalar width, Lynton::scalar height, Lynton::scalar friction, unsigned short tex_id)
    : m_border_width(renderer->get_screen_width()),
      m_border_height(renderer->get_screen_height()),
      m_anti_friction(1 - friction),
      m_tex_quad(new Lynton::TexQuad(renderer, camera, pos, width, height))
{
    m_tex_quad->set_texture_id(tex_id);
}

void Quad::accellerate(Lynton::vec3 a)
{
    m_vel += a;
}

void Quad::repel(Lynton::vec3 source, Lynton::scalar strength)
{
    Lynton::vec3 a = m_tex_quad->get_middle() - source;
    a              = strength * 0.03125 * (1 / arma::norm(a)) * a;
    accellerate(a);
}

void Quad::update(Lynton::scalar frame_time)
{
    m_tex_quad->translate(frame_time * m_vel);
    Lynton::vec3 top_left     = m_tex_quad->get_top_left();
    Lynton::vec3 bottom_right = m_tex_quad->get_bottom_right();
    // get reflected at walls
    if(bottom_right[0] >= m_border_width || top_left[0] <= 0) {
        m_vel[0] *= -1;
        m_tex_quad->translate(frame_time * m_vel);
    }
    if(bottom_right[1] >= m_border_height || top_left[1] <= 0) {
        m_vel[1] *= -1;
        m_tex_quad->translate(frame_time * m_vel);
    }
    // friction
    m_vel *= std::pow(m_anti_friction, frame_time);
}
