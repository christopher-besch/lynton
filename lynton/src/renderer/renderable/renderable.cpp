#include "renderable.h"

#include "pch.h"

namespace Lynton {

void Renderable::translate(scalar dx, scalar dy)
{
    m_mat = trans_mat3(dx, dy) * m_mat;
}

void Renderable::rotate(scalar angle)
{
    m_rotation += angle;
    m_mat = rot_mat3(angle) * m_mat;
}

void Renderable::scale(scalar fx, scalar fy)
{
    mat3 mat      = sca_mat3(fx, fy);
    m_mat         = mat * m_mat;
    m_inv_ska_mat = m_inv_ska_mat * mat.i();
}

void Renderable::rotate_at(scalar angle, vec3 pivot)
{
    m_rotation += angle;
    m_mat = trans_mat3(pivot) * rot_mat3(angle) * trans_mat3(-pivot) * m_mat;
}

void Renderable::scale_at(scalar fx, scalar fy, vec3 pivot)
{
    mat3 mat      = sca_mat3(fx, fy);
    m_mat         = trans_mat3(pivot) * mat * trans_mat3(-pivot) * m_mat;
    m_inv_ska_mat = m_inv_ska_mat * mat.i();
}

void Renderable::translate_local_no_scale(vec3 d)
{
    d     = m_inv_ska_mat * d;
    m_mat = m_mat * trans_mat3(d[0], d[1]);
}

void Renderable::translate_local_global_scale(vec3 d)
{
    d     = m_inv_ska_mat * d;
    m_mat = m_mat * trans_mat3(d[0], d[1]);
}

void Renderable::scale_local(vec3 d)
{
}

} // namespace Lynton
