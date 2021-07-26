#pragma once
#include "math/defs.h"
#include "math/matrices.h"

namespace Lynton {

class Camera {
public:
    Camera(vec3 origin, scalar width, scalar height);
    ~Camera();

    void set_location(vec3 origin);
    void translate(scalar dx, scalar dy);
    void translate(vec3 d) { translate(d[0], d[1]); }
    void rotate(scalar angle);
    void scale(scalar fx, scalar fy);
    void flip_hor() { scale(-1, 1); }
    void flip_ver() { scale(1, -1); }

    void rotate_at(scalar angle, vec3 pivot);
    void scale_at(scalar fx, scalar fy, vec3 pivot);
    void flip_hor_at(vec3 pivot);
    void flip_ver_at(vec3 pivot);

    vec3 get_middle() const;
    vec3 get_top_left() const { return m_origin; }
    vec3 get_top_right() const { return m_top_right_corner; }
    vec3 get_bottom_left() const { return m_bottom_left_corner; }
    vec3 get_bottom_right() const { return m_bottom_right_corner; }

    scalar get_rotation() { return m_rotation; }
    bool   get_flip_hor() { return m_flip_hor; }
    bool   get_flip_ver() { return m_flip_ver; }
    mat3   get_mat() { return m_mat; }
    mat3   get_mat_no_rotation() { return m_mat_no_rotation; }

private:
    inline void mul_mat(mat3 mat);
    inline void mul_all_mat(mat3 mat);

private:
    // coordinates in global space
    // top left corner
    vec3 m_origin {0, 0, 1};
    // when rotated or flipped -> m_top_right_corner may not stay the one in the topmost rightmost corner
    vec3 m_top_right_corner {1, 0, 1}, m_bottom_left_corner {0, 1, 1}, m_bottom_right_corner {1, 1, 1};

    // what has to be done to get from global space to camera space
    scalar m_rotation {0};
    bool   m_flip_hor {0}, m_flip_ver {0};
    // used to transform points from global space into the camera space correctly
    mat3 m_mat = {arma::fill::eye};
    // same as m_mat but with no rotation applied
    mat3 m_mat_no_rotation = {arma::fill::eye};
};

} // namespace Lynton
