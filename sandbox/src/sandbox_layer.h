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
    Lynton::TextureLibrary* m_tex_lib = nullptr;
    Lynton::Font*           m_font    = nullptr;

    Lynton::TexQuad* m_tex_quad1 = nullptr;
    Lynton::TexQuad* m_tex_quad2 = nullptr;
};
