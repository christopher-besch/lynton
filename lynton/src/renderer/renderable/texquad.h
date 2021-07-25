#pragma once
#include "renderable.h"
#include "renderer/texture/texture_library.h"

namespace Lynton {
class TexQuad: public Renderable {
public:
    // origin is original top left corner
    // virtual_corner is original bottom right corner but rotations don't get applied
    TexQuad(Renderer* renderer, vec3 origin, vec3 virtual_corner);
    TexQuad(Renderer* renderer, vec3 origin, scalar width, scalar height);

    virtual ~TexQuad();

    void mul_mat(mat3 mat)
    {
        m_origin              = mat * m_origin;
        m_top_rigth_corner    = mat * m_top_rigth_corner;
        m_bottom_left_corner  = mat * m_bottom_left_corner;
        m_bottom_right_corner = mat * m_bottom_right_corner;
    }

    void mul_all_mat(mat3 mat)
    {
        m_virtual_corner = mat * m_virtual_corner;
        mul_mat(mat);
    }

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
    vec3 get_other_corner() const { return m_virtual_corner; }
    vec3 get_top_left() const { return m_origin; }
    vec3 get_top_right() const { return m_top_rigth_corner; }
    vec3 get_bottom_left() const { return m_bottom_left_corner; }
    vec3 get_bottom_right() const { return m_bottom_right_corner; }

private:
    // todo: sub coordinates missing <- sprite sheets
    unsigned short m_texture_id {0};

    // m_origin is top left corner; m_other_corner is bottom right corner
    // <- might not always be correct <- rotation applied after applied after everything else
    vec3   m_virtual_corner {0, 0, 1};
    vec3   m_top_rigth_corner {0, 0, 1}, m_bottom_left_corner {0, 0, 1}, m_bottom_right_corner {0, 0, 1};
    scalar m_rotation {0};
    bool   m_flip_hor {0}, m_flip_ver {0};
};
} // namespace Lynton
