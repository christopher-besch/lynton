#pragma once

#include "lynton.h"

class SandboxLayer: public Lynton::Layer {
public:
    SandboxLayer()
        : Layer("Sandbox Layer") {}
    virtual ~SandboxLayer();

    void setup() override;

    // time in seconds since last frame
    void update(double frame_time) override;
    void render() override;

    // returns true if handled by this layer
    bool handle_event(SDL_Event e) override;

private:
    Lynton::Font* m_font = nullptr;

    Lynton::TexQuad* m_tex_quad1 = nullptr;
    Lynton::TexQuad* m_tex_quad2 = nullptr;

    // acceleration
    bool m_a_l {0}, m_a_r {0}, m_a_u {0}, m_a_d {0};
    // velocity
    Lynton::scalar m_vx {0}, m_vy {0};
    // scaling up and down
    bool m_s_u {0}, m_s_d {0};
};
