#include "texquad.h"

#include "pch.h"

namespace Lynton {
TexQuad::TexQuad(Renderer* renderer, int x, int y, int w, int h, TextureLibrary* texture_library)
    : Renderable(renderer, x, y, w, h), m_texture_library(texture_library)
{
    log_lynton_extra("Creating texture quad");
}

void TexQuad::render()
{
}
} // namespace Lynton
