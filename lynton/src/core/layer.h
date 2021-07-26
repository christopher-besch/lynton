#pragma once

#include "renderer/camera/camera.h"
#include "renderer/renderer.h"

#include <string>

namespace Lynton {

class Layer {
public:
    // todo: make renderer be defined here
    Layer(const std::string& name, vec3 camera_origin = {-1, -1, 1}, scalar camera_width = 2, scalar camera_height = 2);
    virtual ~Layer() = 0;

    // run after construction
    // texture loading should be done here or dynamically in update or render, not in constructor
    virtual void setup() = 0;
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
        m_tex_lib  = renderer->get_texture_library();
    }

protected:
    std::string m_name;
    Camera*     m_camera {nullptr};
    // these get set by set_renderer
    Renderer*               m_renderer {nullptr};
    Lynton::TextureLibrary* m_tex_lib {nullptr};

    friend class Application;
};
} // namespace Lynton
