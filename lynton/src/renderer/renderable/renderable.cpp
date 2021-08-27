#include "renderable.h"

#include "pch.h"

namespace Lynton {

void Renderable::translate(scalar dx, scalar dy)
{
    m_mat = trans_mat3(dx, dy) * m_mat;
}

void Renderable::rotate(scalar angle)
{
    m_mat = rot_mat3(angle) * m_mat;
}

void Renderable::scale(scalar fx, scalar fy)
{
    m_mat = sca_mat3(fx, fy) * m_mat;
}

void Renderable::rotate_at(scalar angle, vec3 pivot)
{
    m_mat = trans_mat3(pivot) * rot_mat3(angle) * trans_mat3(-pivot) * m_mat;
}

void Renderable::scale_at(scalar fx, scalar fy, vec3 pivot)
{
    m_mat = trans_mat3(pivot) * sca_mat3(fx, fy) * trans_mat3(-pivot) * m_mat;
}

} // namespace Lynton
