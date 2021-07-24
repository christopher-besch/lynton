#pragma once
#include "math/defs.h"

#include <armadillo>
#include <cmath>

namespace Lynton {
inline mat3 trans_mat3(scalar dx, scalar dy)
{
    return {
        {1, 0, dx},
        {0, 1, dy},
        {0, 0, 1}};
}

inline mat3 rot_mat3(scalar angle)
{
    // convert degree to radian
    angle /= 180;
    angle *= M_PI;
    scalar sin = std::sin(angle);
    scalar cos = std::cos(angle);
    return {
        {cos, -sin, 0},
        {sin, cos, 0},
        {0, 0, 1}};
}

inline mat3 ska_mat3(scalar fx, scalar fy)
{
    return {
        {fx, 0, 0},
        {0, fy, 0},
        {0, 0, 1}};
}
} // namespace Lynton
