#pragma once

#include "renderer/camera/camera.h"
#include "renderer/renderer.h"

#include <string>

namespace Lynton {

class Layer {
public:
    // todo: make renderer be defined here
    Layer(const std::string& name);
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
    void set_attributes(Renderer* renderer, RandomGen* random_gen, Camera* camera)
    {
        m_renderer = renderer;
        m_tex_lib  = renderer->get_texture_library();

        m_random_gen = random_gen;

        // takes ownership of camera
        m_camera = camera;
    }

protected:
    std::string m_name;
    // these get set by set_renderer
    Renderer*       m_renderer {nullptr};
    RandomGen*      m_random_gen {nullptr};
    TextureLibrary* m_tex_lib {nullptr};
    // owned by layer
    Camera* m_camera {nullptr};

    friend class Application;
};
} // namespace Lynton
