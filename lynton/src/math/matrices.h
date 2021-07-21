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
    scalar sin = std::sin(angle);
    scalar cos = std::cos(angle);
    return {
        {cos, -sin, 0},
        {sin, cos, 0},
        {0, 0, 1}};
}
} // namespace Lynton
