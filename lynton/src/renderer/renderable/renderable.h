#pragma once

#include "renderer/camera/camera.h"
#include "renderer/renderer.h"

namespace Lynton {

class Renderable {
public:
    Renderable(Renderer* renderer, Camera* camera)
        : m_renderer(renderer), m_camera(camera) {}
    virtual ~Renderable() = default;

    // perform transformation at (0, 0)
    // certain limitations in the use of these methods may be set by inheriting classes
    // move entire object to new origin
    virtual void set_location(vec3 origin)       = 0;
    virtual void translate(scalar dx, scalar dy) = 0;
    virtual void translate(vec3 d) { translate(d[0], d[1]); }
    virtual void rotate(scalar angle)        = 0;
    virtual void scale(scalar fx, scalar fy) = 0;
    virtual void flip_hor()                  = 0;
    virtual void flip_ver()                  = 0;

    // perform transformation at pivot
    virtual void rotate_at(scalar angle, vec3 pivot);
    virtual void scale_at(scalar fx, scalar fy, vec3 pivot);
    virtual void flip_hor_at(vec3 pivot);
    virtual void flip_ver_at(vec3 pivot);

    virtual void render() const = 0;

    vec3 get_origin() const { return m_origin; }

protected:
    Renderer* m_renderer {nullptr};
    Camera*   m_camera {nullptr};
    vec3      m_origin {0, 0, 1};
};

} // namespace Lynton
