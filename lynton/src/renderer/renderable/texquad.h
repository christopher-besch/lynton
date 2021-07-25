#pragma once
#include "renderable.h"
#include "renderer/texture/texture_library.h"

namespace Lynton {
class TexQuad: public Renderable {
public:
    // origin is original top left corner
    // orther_corner is original bottom right corner
    TexQuad(Renderer* renderer, vec3 origin, vec3 orther_corner);
    TexQuad(Renderer* renderer, vec3 origin, scalar width, scalar height);

    virtual ~TexQuad();

    virtual void set_location(vec3 origin) override;
    virtual void translate(scalar dx, scalar dy) override;
    virtual void translate(vec3 d) override { translate(d[0], d[1]); }
    virtual void rotate(scalar angle) override;
    // doesn't support prior rotation
    virtual void scale(scalar fx, scalar fy) override;
    virtual void flip_hor() override { scale(-1, 1); }
    virtual void flip_ver() override { scale(1, -1); }

    virtual void rotate_at(scalar angle, vec3 pivot) override;
    // doesn't support prior rotation
    virtual void scale_at(scalar fx, scalar fy, vec3 pivot) override;
    virtual void flip_hor_at(vec3 pivot) override;
    virtual void flip_ver_at(vec3 pivot) override;

    virtual void render() const override;

    void           set_texture_id(unsigned short id) { m_texture_id = id; }
    unsigned short get_texture_id() const { return m_texture_id; }

    vec3 get_middle() const;

private:
    // todo: sub coordinates missing <- sprite sheets
    unsigned short m_texture_id {0};

    // m_origin is top left corner; m_other_corner is bottom right corner
    // <- might not always be correct <- rotation applied after applied after everything else
    vec3   m_other_corner {0, 0, 1};
    scalar m_rotation {0};
};
} // namespace Lynton
