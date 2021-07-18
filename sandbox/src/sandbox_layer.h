#pragma once

#include "lynton.h"

class SandboxLayer: public Lynton::Layer {
public:
    SandboxLayer()
        : Layer("Sandbox Layer") {}
    virtual ~SandboxLayer() = default;

    void start() override;

    // time in seconds since last frame
    void update(double frame_time) override;
    void render() override;

    // returns true if handled by this layer
    bool handle_event(SDL_Event e) override;

private:
    Lynton::TexQuad* m_tex_quad = nullptr;
};
