#pragma once

#include "lynton.h"

class SandboxLayer: public Lynton::Layer {
public:
    SandboxLayer()
        : Layer("Sandbox Layer", {0, 0, 1}, 1600, 1200) {}
    virtual ~SandboxLayer();

    void setup() override;

    // time in seconds since last frame
    void update(double frame_time) override;
    void render() override;

    // returns true if handled by this layer
    bool handle_event(SDL_Event e) override;

private:
    Lynton::Font* m_font {nullptr};

    Lynton::TexQuad* m_smiley {nullptr};
    Lynton::TexQuad* m_dot1 {nullptr};
    Lynton::TexQuad* m_dot2 {nullptr};
    Lynton::TexQuad* m_dot3 {nullptr};
    Lynton::TexQuad* m_dot4 {nullptr};
    Lynton::TexQuad* m_dot5 {nullptr};

    // acceleration
    bool m_a_left {0}, m_a_right {0}, m_a_up {0}, m_a_down {0};
    // velocity
    Lynton::scalar m_v_right {0}, m_v_down {0};

    bool m_scale_up {0}, m_scale_down {0};

    bool m_rotate_left {0}, m_rotate_right {0};
};
