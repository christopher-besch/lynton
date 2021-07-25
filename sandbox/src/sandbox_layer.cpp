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

    for(int x = 0; x < m_tex_lib->get_height(img_id); ++x)
        for(int y = 0; y < m_tex_lib->get_width(img_id); ++y)
            if(x % 2 && y % 2)
                pixels[x + y * m_tex_lib->get_width(img_id)] = m_renderer->get_color(0x10, 0x50, 0xff, 0xff);

    m_tex_lib->unlock(img_id);

    // text
    // unsigned short text_id = m_tex_lib->load_from_text("Hello World!", {0xff, 0x20, 0x20, 0xff}, m_font);
    unsigned short red_dot_id = m_tex_lib->create_blank(5, 5);
    m_tex_lib->lock(red_dot_id);
    pixels = static_cast<uint32_t*>(m_tex_lib->get_pixels(red_dot_id));

    for(int i = 0; i < m_tex_lib->get_pixel_count(red_dot_id); ++i) {
        pixels[i] = m_renderer->get_color(0x00, 0x00, 0xff, 0xff);
    }
    m_tex_lib->unlock(red_dot_id);

    m_tex_quad1 = new Lynton::TexQuad(m_renderer, {100, 100, 1}, {150, 150, 1});
    m_tex_quad1->set_texture_id(img_id);

    m_tex_quad2 = new Lynton::TexQuad(m_renderer, {20, 20, 1}, m_tex_lib->get_width(red_dot_id), m_tex_lib->get_height(red_dot_id));
    m_tex_quad2->set_texture_id(red_dot_id);
}

void SandboxLayer::update(double frame_time)
{
    // translate objects
    m_v_right += 200 * frame_time * (m_a_right - m_a_left);
    m_v_down += 200 * frame_time * (m_a_down - m_a_up);
    m_tex_quad1->translate(m_v_right * frame_time, m_v_down * frame_time);

    // scale
    Lynton::scalar scale_factor = 1 / (1 + 3 * frame_time * (m_scale_up - m_scale_down));
    m_tex_quad1->scale_at(scale_factor, scale_factor, m_tex_quad1->get_middle());

    // rotate
    m_tex_quad1->rotate_at(90 * (m_rotate_right - m_rotate_left) * frame_time, m_tex_quad1->get_middle());

    // move red dot
    m_tex_quad2->set_location(m_tex_quad1->get_middle());
}

void SandboxLayer::render()
{
    m_tex_quad1->render();
    m_tex_quad2->render();
}

bool SandboxLayer::handle_event(SDL_Event e)
{
    // todo: filter out repetitions
    if(e.type == SDL_KEYDOWN) {
        switch(e.key.keysym.sym) {
            // translation
        case SDLK_w:
            m_a_up = true;
            return true;
        case SDLK_s:
            m_a_down = true;
            return true;
        case SDLK_a:
            m_a_left = true;
            return true;
        case SDLK_d:
            m_a_right = true;
            return true;

            // scaling
        case SDLK_q:
            m_scale_up = true;
            return true;
        case SDLK_e:
            m_scale_down = true;
            return true;

            // flipping
        case SDLK_r:
            m_tex_quad1->flip_hor_at(m_tex_quad1->get_middle());
            return true;
        case SDLK_f:
            m_tex_quad1->flip_ver_at(m_tex_quad1->get_middle());
            return true;

            // rotation
        case SDLK_t:
            m_rotate_left = true;
            return true;
        case SDLK_g:
            m_rotate_right = true;
            return true;
        }
    }
    else if(e.type == SDL_KEYUP) {
        switch(e.key.keysym.sym) {
            // translation
        case SDLK_w:
            m_a_up = false;
            return true;
        case SDLK_s:
            m_a_down = false;
            return true;
        case SDLK_a:
            m_a_left = false;
            return true;
        case SDLK_d:
            m_a_right = false;
            return true;

            // scaling
        case SDLK_q:
            m_scale_up = false;
            return true;
        case SDLK_e:
            m_scale_down = false;
            return true;

            // rotation
        case SDLK_t:
            m_rotate_left = false;
            return true;
        case SDLK_g:
            m_rotate_right = false;
            return true;
        }
    }
    return false;
}
