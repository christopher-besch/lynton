#pragma once
#include "renderable.h"
#include "renderer/camera/camera.h"
#include "renderer/texture/texture_library.h"

namespace Lynton {
class TexQuad: public Renderable {
public:
    TexQuad(Renderer* renderer, Camera* camera, vec3 top_left, scalar width, scalar height);
    virtual ~TexQuad();

    virtual void render() const override;

    vec3 get_top_left() const { return m_mat * vec3 {0, 0, 1}; }
    vec3 get_top_right() const { return m_mat * vec3 {1, 0, 1}; }
    vec3 get_bottom_left() const { return m_mat * vec3 {0, 1, 1}; }
    vec3 get_bottom_right() const { return m_mat * vec3 {1, 1, 1}; }
    vec3 get_middle() const;

    unsigned short get_texture_id() const { return m_texture_id; }
    void           set_texture_id(unsigned short id) { m_texture_id = id; }

private:
    // todo: sub coordinates missing <- sprite sheets
    unsigned short m_texture_id {0};

    scalar m_rotation {0};
};
} // namespace Lynton
