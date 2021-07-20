#pragma once
#include "renderable.h"
#include "renderer/texture/texture_library.h"

#include <armadillo>

namespace Lynton {
class TexQuad: public Renderable {
public:
    TexQuad(Renderer* renderer, arma::vec3 origin, arma::vec3 scale);

    virtual ~TexQuad();

    void render() override;

    void           set_texture_id(unsigned short id) { m_texture_id = id; }
    unsigned short get_texture_id() { return m_texture_id; }

private:
    // todo: sub coordinates missing <- sprite sheets
    unsigned short m_texture_id;

    arma::vec3 m_scale;
};
} // namespace Lynton
