#include "sandbox_layer.h"

#include <iostream>
#include <stdio.h>

SandboxLayer::~SandboxLayer()
{
    delete m_tex_quad1;
    delete m_tex_quad2;
}

void SandboxLayer::setup()
{
    m_font = new Lynton::Font("res/iosevka-extendedbold.ttf", 50);

    // image
    unsigned short img_id = m_tex_lib->load_from_file("res/test.png");

    m_tex_lib->lock(img_id);
    uint32_t* pixels = static_cast<uint32_t*>(m_tex_lib->get_pixels(img_id));
    // 4 <- RGBA
    // -> gives amount of pixels per line
    int pixel_count = (m_tex_lib->get_pitch(img_id) / 4) * m_tex_lib->get_h(img_id);

    SDL_PixelFormat* mapping_format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

    for(int x = 0; x < m_tex_lib->get_h(img_id); ++x)
        for(int y = 0; y < m_tex_lib->get_w(img_id); ++y)
            if(x % 2 && y % 2)
                pixels[x + y * m_tex_lib->get_w(img_id)] = SDL_MapRGBA(mapping_format, 0x10, 0x50, 0xff, 0xff);

    m_tex_lib->unlock(img_id);
    SDL_FreeFormat(mapping_format);

    // text
    unsigned short text_id = m_tex_lib->load_from_text("Hello World!", {0xff, 0x20, 0x20, 0xff}, m_font);

    m_tex_quad1 = new Lynton::TexQuad(m_renderer, {100, 100, 1}, {50, 50, 1});
    m_tex_quad1->set_texture_id(img_id);

    m_tex_quad2 = new Lynton::TexQuad(m_renderer, {20, 20, 1}, m_tex_lib->get_scale(text_id));
    m_tex_quad2->set_texture_id(text_id);
}

void SandboxLayer::update(double frame_time)
{
    // move objects
    // m_tex_quad1->rotate(90 * frame_time);

    m_vx += 500 * frame_time * (m_a_r - m_a_l);
    m_vy += 500 * frame_time * (m_a_d - m_a_u);

    m_tex_quad1->translate(m_vx * frame_time, m_vy * frame_time);
}

void SandboxLayer::render()
{
    m_tex_quad1->render();
    // m_tex_quad2->render();
}

bool SandboxLayer::handle_event(SDL_Event e)
{
    if(e.type == SDL_KEYDOWN) {
        switch(e.key.keysym.sym) {
        case SDLK_w:
            m_a_u = true;
            return true;
        case SDLK_s:
            m_a_d = true;
            return true;
        case SDLK_a:
            m_a_l = true;
            return true;
        case SDLK_d:
            m_a_r = true;
            return true;
        }
    }
    else if(e.type == SDL_KEYUP) {
        switch(e.key.keysym.sym) {
        case SDLK_w:
            m_a_u = false;
            return true;
        case SDLK_s:
            m_a_d = false;
            return true;
        case SDLK_a:
            m_a_l = false;
            return true;
        case SDLK_d:
            m_a_r = false;
            return true;
        }
    }
    return false;
}
