#pragma once
#include "math/defs.h"
#include "math/matrices.h"

namespace Lynton {

class Camera {
public:
    Camera(vec3 top_left, scalar width, scalar height);
    ~Camera();

    // global translation -> local to objects looked at, which are in global space
    void translate(scalar dx, scalar dy);
    void translate(vec3 d) { translate(d[0], d[1]); }
    // local translation with local scale applied -> using rotation of camera
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

    vec3 get_top_left() const { return m_mat * vec3 {0, 0, 1}; }
    vec3 get_top_right() const { return m_mat * vec3 {m_width, 0, 1}; }
    vec3 get_bottom_left() const { return m_mat * vec3 {0, m_height, 1}; }
    vec3 get_bottom_right() const { return m_mat * vec3 {m_width, m_height, 1}; }
    vec3 get_middle() const;

    const mat3& get_mat() const { return m_mat; }
    scalar      get_rotation() const { return m_rotation; }
    const mat3& get_inv_mat() const { return m_inv_mat; }
    scalar      get_inv_rotation() const { return m_inv_rotation; }

    // todo: set total transformation
    // void set_location(vec3 origin);
    // void set_rotation(scalar origin);
    // void set_scale(scalar scalar fx, scalar fy);

private:
    scalar m_width {0}, m_height {0};

    mat3   m_mat {arma::fill::eye};
    scalar m_rotation {0};
    mat3   m_inv_ska_mat {arma::fill::eye};
    // what has to be done to get from global space to camera space
    // used to transform points from global space into the camera space
    mat3   m_inv_mat {arma::fill::eye};
    scalar m_inv_rotation {0};
};

} // namespace Lynton
