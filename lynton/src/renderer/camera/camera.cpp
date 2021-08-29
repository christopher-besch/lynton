#include "camera.h"

#include "pch.h"

namespace Lynton {

Camera::Camera(vec3 top_left, scalar width, scalar height)
    : m_width(width), m_height(height)
{
    log_lynton_general("Creating Camera at ({}, {}) with width: {} and height: {}", top_left[0], top_left[1], width, height);
    translate(top_left);
}
Camera::~Camera()
{
    log_lynton_general("Deleting Camera");
}

// translate
void Camera::translate(scalar dx, scalar dy)
{
    mat3 mat = trans_mat3(dx, dy);

    m_mat     = mat * m_mat;
    m_inv_mat = m_inv_mat * mat.i();
}
void Camera::translate_local(scalar dx, scalar dy)
{
    mat3 mat = trans_mat3(dx, dy);

    m_mat     = m_mat * mat;
    m_inv_mat = mat.i() * m_inv_mat;
}
void Camera::translate_local_global_scale(vec3 d)
{
    d        = m_inv_ska_mat * d;
    mat3 mat = trans_mat3(d);

    m_mat     = m_mat * mat;
    m_inv_mat = mat.i() * m_inv_mat;
}

// rotate
void Camera::rotate(scalar angle)
{
    mat3 mat = rot_mat3(angle);

    m_rotation += angle;
    m_inv_rotation -= angle;
    m_mat     = mat * m_mat;
    m_inv_mat = m_inv_mat * mat.i();
}
void Camera::rotate_at(scalar angle, vec3 pivot)
{
    mat3 mat        = rot_mat3(angle);
    mat3 pivot_mat  = trans_mat3(pivot);
    mat3 npivot_mat = trans_mat3(-pivot);

    m_rotation += angle;
    m_inv_rotation -= angle;

    m_mat     = pivot_mat * mat * npivot_mat * m_mat;
    m_inv_mat = m_inv_mat * npivot_mat.i() * mat.i() * pivot_mat.i();
}

// scale
void Camera::scale(scalar fx, scalar fy)
{
    mat3 mat     = sca_mat3(fx, fy);
    mat3 inv_mat = mat.i();

    m_mat         = mat * m_mat;
    m_inv_mat     = m_inv_mat * inv_mat;
    m_inv_ska_mat = m_inv_ska_mat * inv_mat;
}
void Camera::scale_at(scalar fx, scalar fy, vec3 pivot)
{
    mat3 mat        = sca_mat3(fx, fy);
    mat3 inv_mat    = mat.i();
    mat3 pivot_mat  = trans_mat3(pivot);
    mat3 npivot_mat = trans_mat3(-pivot);

    m_mat         = pivot_mat * mat * npivot_mat * m_mat;
    m_inv_mat     = m_inv_mat * npivot_mat.i() * inv_mat * pivot_mat.i();
    m_inv_ska_mat = m_inv_ska_mat * inv_mat;
}
void Camera::scale_local(scalar fx, scalar fy)
{
    mat3 mat      = sca_mat3(fx, fy);
    mat3 inv_mat  = mat.i();
    m_mat         = m_mat * mat;
    m_inv_mat     = inv_mat * m_inv_mat;
    m_inv_ska_mat = m_inv_ska_mat * inv_mat;
}

vec3 Camera::get_middle() const
{
    vec3 top_left     = get_top_left();
    vec3 bottom_right = get_bottom_right();
    // adding half the diagonal
    return top_left + (bottom_right - top_left) / 2;
}

} // namespace Lynton
