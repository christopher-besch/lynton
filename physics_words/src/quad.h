#pragma once

#include "lynton.h"

class Quad {
public:
    Quad(Lynton::Renderer* renderer, Lynton::Camera* camera, Lynton::vec3 pos, Lynton::scalar width, Lynton::scalar height, Lynton::scalar friction, unsigned short tex_id);
    ~Quad() { delete m_tex_quad; }

    void accellerate(Lynton::vec3 a);
    void repel(Lynton::vec3 source, Lynton::scalar strength);

    void update(Lynton::scalar frame_time);
    void render() { m_tex_quad->render(); }

private:
    Lynton::scalar m_border_width {0}, m_border_height {0};
    Lynton::scalar m_anti_friction;
    // third coordinate is gibberish
    Lynton::vec3     m_vel {0, 0, 1};
    Lynton::TexQuad* m_tex_quad {nullptr};
};
