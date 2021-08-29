#pragma once

#include "renderer/camera/camera.h"
#include "renderer/renderer.h"

namespace Lynton {

class Renderable {
public:
    Renderable(Renderer* renderer, Camera* camera, vec3 top_left);
    virtual ~Renderable() = default;

    // global translation
    void translate(scalar dx, scalar dy);
    void translate(vec3 d) { translate(d[0], d[1]); }
    // local translation with local scale applied -> using rotation of object
    void translate_local(scalar dx, scalar dy);
    void translate_local(vec3 d) { translate_local(d[0], d[1]); };
    // locale translation with global scale applied
    void translate_local_global_scale(scalar dx, scalar dy) { translate_local_global_scale({dx, dy, 1}); }
    void translate_local_global_scale(vec3 d);

    // warning: rotation connected with uneven scaling can cause shearing wich might not be supported
    void rotate(scalar angle);
    // rotate at pivot
    void rotate_at(scalar angle, vec3 pivot);

    void scale(scalar fx, scalar fy);
    void scale(scalar f) { scale(f, f); }
    // scale with pivot as center
    void scale_at(scalar fx, scalar fy, vec3 pivot);
    void scale_at(scalar f, vec3 pivot) { scale_at(f, f, pivot); }
    // local scale -> using rotation of object
    void scale_local(scalar fx, scalar fy);
    void scale_local(scalar f) { scale_local(f, f); }

    virtual void render() const = 0;

    const mat3& get_mat() const { return m_mat; }
    scalar      get_rotation() const { return m_rotation; }

    // todo: set total transformation
    // void set_location(vec3 origin);
    // void set_rotation(scalar origin);
    // void set_scale(scalar scalar fx, scalar fy);
    // void scale_local_at(scalar fx, scalar fy, vec3 pivot);

protected:
    Renderer* m_renderer {nullptr};
    Camera*   m_camera {nullptr};

    mat3   m_mat {arma::fill::eye};
    mat3   m_inv_ska_mat {arma::fill::eye};
    scalar m_rotation {0};
};

} // namespace Lynton
