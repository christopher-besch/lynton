#pragma once
#include "renderable.h"
#include "renderer/texture/texture_library.h"

namespace Lynton {
class TexQuad: public Renderable {
public:
    TexQuad(Renderer* renderer, int x, int y, int w, int h, TextureLibrary* texture_library);

    virtual ~TexQuad() = default;

    void render() override;

private:
    // todo: sub coordinates missing <- sprite sheets
    TextureLibrary* m_texture_library = nullptr;
    unsigned short  m_texture_id;
};
} // namespace Lynton
