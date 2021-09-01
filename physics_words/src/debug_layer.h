#pragma once

#include "lynton.h"

class DebugLayer: public Lynton::Layer {
public:
    DebugLayer()
        : Layer("Debug Layer") {}
    virtual ~DebugLayer();

    void setup() override;

    // time in seconds since last frame
    void update(double frame_time) override;
    void render() override;

    // returns true if handled by this layer
    bool handle_event(SDL_Event e) override;

private:
    Lynton::Font*    m_font     = nullptr;
    Lynton::TexQuad* m_fps_quad = nullptr;
};
