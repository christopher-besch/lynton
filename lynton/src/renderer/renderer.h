#pragma once

#include <SDL.h>
#include <string>

namespace Lynton {
class Renderer {
public:
    Renderer(const std::string& name, int screen_width, int screen_height);
};
} // namespace Lynton
