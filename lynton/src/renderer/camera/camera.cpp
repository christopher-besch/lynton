#include "camera.h"

#include "pch.h"

namespace Lynton {

Camera::Camera(vec3 origin, scalar width, scalar height)
{
    scale(width, height);
    translate(origin);
    vec3 diagonal = m_bottom_right_corner - m_origin;
    std::cout << m_mat << std::endl;
    std::cout << m_mat_no_rotation << std::endl;
    log_lynton_general("Creating Camera at ({}, {}) with width: {} and height: {}", m_origin[0], m_origin[1], diagonal[0], diagonal[1]);
}

Camera::~Camera()
{
    log_lynton_general("Deleting Camera");
}

/////////////////////
// transformations //
/////////////////////
void Camera::set_location(vec3 origin)
{
    // how to move old origin to get to new
    vec3 direction = origin - m_origin;
    translate(direction[0], direction[1]);
}

void Camera::translate(scalar dx, scalar dy)
{
    mul_all_mat(trans_mat3(dx, dy));
}

void Camera::rotate(scalar angle)
{
    mul_mat(rot_mat3(angle));
    // other way around
    if(m_flip_hor != m_flip_ver)
        m_rotation += angle;
    else
        m_rotation -= angle;
}

void Camera::scale(scalar fx, scalar fy)
{
    mul_all_mat(sca_mat3(fx, fy));
    if(fx < 0)
        m_flip_hor = !m_flip_hor;
    if(fy < 0)
        m_flip_ver = !m_flip_ver;
}

/////////////////////////////
// transformation at pivot //
/////////////////////////////
void Camera::rotate_at(scalar angle, vec3 pivot)
{
    // translate so that pivot is (0, 0)
    translate(-pivot);
    rotate(angle);
    // translate back
    translate(pivot);
}

void Camera::scale_at(scalar fx, scalar fy, vec3 pivot)
{
    translate(-pivot);
    scale(fx, fy);
    translate(pivot);
}

void Camera::flip_hor_at(vec3 pivot)
{
    translate(-pivot);
    flip_hor();
    translate(pivot);
}

void Camera::flip_ver_at(vec3 pivot)
{
    translate(-pivot);
    flip_ver();
    translate(pivot);
}

vec3 Camera::get_middle() const
{
    vec3 half_diagonal = (m_bottom_right_corner - m_origin) / 2;
    return m_origin + half_diagonal;
}

void Camera::mul_mat(mat3 mat)
{
    m_origin              = mat * m_origin;
    m_top_right_corner    = mat * m_top_right_corner;
    m_bottom_left_corner  = mat * m_bottom_left_corner;
    m_bottom_right_corner = mat * m_bottom_right_corner;
    // reverse transformation with inverse matrix
    m_mat = mat.i() * m_mat;
}

void Camera::mul_all_mat(mat3 mat)
{
    m_mat_no_rotation = mat.i() * m_mat_no_rotation;
    mul_mat(mat);
}

} // namespace Lynton
