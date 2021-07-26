#include "renderable.h"

#include "pch.h"

namespace Lynton {

void Renderable::rotate_at(scalar angle, vec3 pivot)
{
    // translate so that pivot is (0, 0)
    translate(-pivot);
    rotate(angle);
    // translate back
    translate(pivot);
}

void Renderable::scale_at(scalar fx, scalar fy, vec3 pivot)
{
    translate(-pivot);
    scale(fx, fy);
    translate(pivot);
}

void Renderable::flip_hor_at(vec3 pivot)
{
    translate(-pivot);
    flip_hor();
    translate(pivot);
}

void Renderable::flip_ver_at(vec3 pivot)
{
    translate(-pivot);
    flip_ver();
    translate(pivot);
}

} // namespace Lynton
