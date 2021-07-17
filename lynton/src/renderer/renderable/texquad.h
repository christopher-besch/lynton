#pragma once
#include "renderable.h"
#include "renderer/texture/texture_library.h"

namespace Lynton {
class TexQuad: public Renderable {
public:
    TexQuad(Renderer* renderer, int x, int y);

    virtual ~TexQuad() = default;

    void render() override;

    void           set_texture_id(unsigned short id) { m_texture_id = id; }
    unsigned short get_texture_id() { return m_texture_id; }

private:
    // todo: sub coordinates missing <- sprite sheets
    unsigned short m_texture_id;
};
} // namespace Lynton
