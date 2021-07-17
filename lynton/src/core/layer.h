#pragma once

#include "renderer/renderer.h"

#include <SDL.h>
#include <string>

namespace Lynton {

class Layer {
public:
    Layer(const std::string& name);
    virtual ~Layer() = 0;

    // time in seconds since last frame
    virtual void update(double frame_time) = 0;
    virtual void render()                  = 0;

    // todo: replace with lynton wrapper event
    // returns true if handled by this layer
    virtual bool handle_event(SDL_Event e) = 0;

protected:
    void set_renderer(Renderer* renderer)
    {
        m_renderer = renderer;
    }

protected:
    std::string m_name;
    Renderer*   m_renderer = nullptr;

    friend class Application;
};
} // namespace Lynton
