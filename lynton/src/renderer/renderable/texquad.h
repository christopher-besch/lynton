#pragma once
#include "renderable.h"
#include "renderer/texture/texture_library.h"

namespace Lynton {
class TexQuad: public Renderable {
public:
    TexQuad(Renderer* renderer, vec3 origin, vec3 scale);

    virtual ~TexQuad();

    virtual void translate(scalar dx, scalar dy) override;
    virtual void rotate(scalar angle) override;
    virtual void scale(scalar fx, scalar fy) override;
    virtual void mirror_hor() override;
    virtual void mirror_ver() override;

    virtual void render() override;

    void           set_texture_id(unsigned short id) { m_texture_id = id; }
    unsigned short get_texture_id() { return m_texture_id; }

private:
    // todo: sub coordinates missing <- sprite sheets
    unsigned short m_texture_id {0};

    vec3   m_scale {0, 0, 0};
    scalar m_rotation {0};
    bool   m_flip_hor {0}, m_flip_ver {0};
};
} // namespace Lynton
