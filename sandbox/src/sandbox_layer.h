#pragma once

#include "lynton.h"

class SandboxLayer: public Lynton::Layer {
public:
    SandboxLayer();
    virtual ~SandboxLayer() = default;

    // ticks since last frame
    virtual void update(uint8_t ticks) override;
    virtual void render() override;

    // returns true if handled by this layer
    virtual bool handle_event(SDL_Event e) override;
};
