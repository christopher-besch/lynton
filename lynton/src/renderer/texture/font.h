#pragma once

#include <SDL_ttf.h>
#include <string>

namespace Lynton {
class Font {
public:
    Font(const std::string& path, int size)
        : m_font(TTF_OpenFont(path.c_str(), size)) {}

    TTF_Font* get_font() { return m_font; }

private:
    TTF_Font* m_font = nullptr;
};
} // namespace Lynton
