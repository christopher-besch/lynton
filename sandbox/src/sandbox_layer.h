#pragma once

#include "lynton.h"

class SandboxLayer: public Lynton::Layer {
public:
    SandboxLayer();
    virtual ~SandboxLayer() = default;

    // time in seconds since last frame
    virtual void update(double frame_time) override;
    virtual void render() override;

    // returns true if handled by this layer
    virtual bool handle_event(SDL_Event e) override;
};
