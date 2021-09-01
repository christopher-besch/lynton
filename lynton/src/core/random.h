#pragma once

#include <limits>
#include <random>

namespace Lynton {

class RandomGen {
public:
    template<typename T>
    T next(T min, T max)
    {
        return next_d(min, max);
    }
    // anything expressible with this type
    template<typename T>
    T next()
    {
        return next<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    }

private:
    // in [0, 1]
    double next_d_1_0()
    {
        uint64_t val = static_cast<uint64_t>(random()) | static_cast<uint64_t>(random()) << 32;
        return val / static_cast<double>(UINT64_MAX);
    }
    double next_d(double min, double max)
    {
        return min + (max - min) * next_d_1_0();
    }

private:
    std::random_device random_device;
    std::mt19937       random = std::mt19937(random_device());
};

} // namespace Lynton
