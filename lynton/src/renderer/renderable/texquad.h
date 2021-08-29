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
    vec3 get_top_right() const { return m_mat * vec3 {m_width, 0, 1}; }
    vec3 get_bottom_left() const { return m_mat * vec3 {0, m_height, 1}; }
    vec3 get_bottom_right() const { return m_mat * vec3 {m_width, m_height, 1}; }
    vec3 get_middle() const;

    vec3 get_top_left_mat(const mat3& mat) const { return mat * vec3 {0, 0, 1}; }
    vec3 get_top_right_mat(const mat3& mat) const { return mat * vec3 {m_width, 0, 1}; }
    vec3 get_bottom_left_mat(const mat3& mat) const { return mat * vec3 {0, m_height, 1}; }
    vec3 get_bottom_right_mat(const mat3& mat) const { return mat * vec3 {m_width, m_height, 1}; }
    vec3 get_middle_mat(const mat3& mat) const;

    unsigned short get_texture_id() const { return m_texture_id; }
    void           set_texture_id(unsigned short id) { m_texture_id = id; }

private:
    scalar m_width {0}, m_height {0};
    // todo: sub coordinates missing <- sprite sheets
    unsigned short m_texture_id {0};
};
} // namespace Lynton
