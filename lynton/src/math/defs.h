#pragma once

#include <armadillo>

namespace Lynton {
typedef float scalar;

typedef arma::fvec::fixed<2> vec2;
typedef arma::fvec::fixed<3> vec3;

typedef arma::fmat::fixed<2, 2> mat2;
typedef arma::fmat::fixed<3, 3> mat3;
} // namespace Lynton
