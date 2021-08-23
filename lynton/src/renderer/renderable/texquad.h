#pragma once
#include "renderable.h"
#include "renderer/camera/camera.h"
#include "renderer/texture/texture_library.h"

namespace Lynton {
class TexQuad: public Renderable {
public:
    TexQuad(Renderer* renderer, Camera* camera);
    // origin is original top left corner
    TexQuad(Renderer* renderer, Camera* camera, vec3 origin, scalar width, scalar height);
    virtual ~TexQuad();

    virtual void set_location(vec3 origin) override;
    virtual void translate(scalar dx, scalar dy) override;
    // misaligns m_scale -> uneven scaling won't be correct
    virtual void rotate(scalar angle) override;
    virtual void scale(scalar fx, scalar fy) override;
    virtual void flip_hor() override { scale(-1, 1); }
    virtual void flip_ver() override { scale(1, -1); }

    virtual void render() const override;

    vec3 get_middle() const;
    vec3 get_top_left() const { return m_origin; }
    vec3 get_top_right() const { return m_top_right_corner; }
    vec3 get_bottom_left() const { return m_bottom_left_corner; }
    vec3 get_bottom_right() const { return m_bottom_right_corner; }

    unsigned short get_texture_id() const { return m_texture_id; }
    void           set_texture_id(unsigned short id) { m_texture_id = id; }

private:
    // todo: copy bad
    inline void mul_mat(mat3 mat);
    inline void mul_all_mat(mat3 mat);

private:
    // todo: sub coordinates missing <- sprite sheets
    unsigned short m_texture_id {0};

    // m_origin is top left corner
    // when rotated or flipped -> m_top_right_corner may not stay the one in the topmost rightmost corner
    vec3 m_top_right_corner {1, 0, 1}, m_bottom_left_corner {0, 1, 1}, m_bottom_right_corner {1, 1, 1};
    // bottom right corner without any rotations applied
    // used to achieve above vertices with sdl <- sdl applies rotation later on
    vec3   m_virtual_corner {1, 1, 1};
    scalar m_rotation {0};
    bool   m_flip_hor {0}, m_flip_ver {0};
};
} // namespace Lynton
