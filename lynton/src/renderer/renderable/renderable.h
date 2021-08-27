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
    void translate(scalar dx, scalar dy);
    void translate(vec3 d) { translate(d[0], d[1]); }
    void rotate(scalar angle);
    void scale(scalar fx, scalar fy);

    // todo: set total transformation
    // void set_location(vec3 origin);
    // void set_rotation(scalar origin);
    // void set_scale(scalar scalar fx, scalar fy);

    // perform transformation at pivot
    void rotate_at(scalar angle, vec3 pivot);
    void scale_at(scalar fx, scalar fy, vec3 pivot);

    // locat transforms
    void translate_local(scalar dx, scalar dy);
    void translate_local(vec3 d) { translate_local(d[0], d[1]); }

    virtual void render() const = 0;

    vec3 get_mat() const { return m_mat; }

protected:
    Renderer* m_renderer {nullptr};
    Camera*   m_camera {nullptr};
    mat3      m_mat {arma::fill::eye};
    mat3      m_inv_ska_mat {arma::fill::eye};
    scalar    m_rotation {0};
};

} // namespace Lynton
