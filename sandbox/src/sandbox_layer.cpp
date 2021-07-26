#include "sandbox_layer.h"

#include <iostream>
#include <stdio.h>

SandboxLayer::~SandboxLayer()
{
    delete m_smiley;
    delete m_dot1;
    delete m_dot2;
    delete m_dot3;
    delete m_dot4;
    delete m_dot5;
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
    unsigned short dot_id1 = m_tex_lib->create_blank(5, 5);
    m_tex_lib->lock(dot_id1);
    pixels = static_cast<uint32_t*>(m_tex_lib->get_pixels(dot_id1));
    for(int i = 0; i < m_tex_lib->get_pixel_count(dot_id1); ++i) {
        pixels[i] = m_renderer->get_color(0x00, 0x00, 0xff, 0xff);
    }
    m_tex_lib->unlock(dot_id1);

    unsigned short dot_id2 = m_tex_lib->create_blank(5, 5);
    m_tex_lib->lock(dot_id2);
    pixels = static_cast<uint32_t*>(m_tex_lib->get_pixels(dot_id2));
    for(int i = 0; i < m_tex_lib->get_pixel_count(dot_id2); ++i) {
        pixels[i] = m_renderer->get_color(0xff, 0x00, 0x00, 0xff);
    }
    m_tex_lib->unlock(dot_id2);

    unsigned short dot_id3 = m_tex_lib->create_blank(5, 5);
    m_tex_lib->lock(dot_id3);
    pixels = static_cast<uint32_t*>(m_tex_lib->get_pixels(dot_id3));
    for(int i = 0; i < m_tex_lib->get_pixel_count(dot_id3); ++i) {
        pixels[i] = m_renderer->get_color(0x00, 0xff, 0x00, 0xff);
    }
    m_tex_lib->unlock(dot_id3);

    m_smiley = new Lynton::TexQuad(m_renderer, m_camera, {100, 100, 1}, 50, 50);
    m_smiley->set_texture_id(img_id);

    m_dot1 = new Lynton::TexQuad(m_renderer, m_camera, {20, 20, 1}, m_tex_lib->get_width(dot_id1), m_tex_lib->get_height(dot_id1));
    m_dot1->set_texture_id(dot_id1);
    m_dot2 = new Lynton::TexQuad(m_renderer, m_camera, {20, 20, 1}, m_tex_lib->get_width(dot_id2), m_tex_lib->get_height(dot_id2));
    m_dot2->set_texture_id(dot_id2);
    m_dot3 = new Lynton::TexQuad(m_renderer, m_camera, {20, 20, 1}, m_tex_lib->get_width(dot_id3), m_tex_lib->get_height(dot_id3));
    m_dot3->set_texture_id(dot_id3);
    m_dot4 = new Lynton::TexQuad(m_renderer, m_camera, {20, 20, 1}, m_tex_lib->get_width(dot_id1), m_tex_lib->get_height(dot_id1));
    m_dot4->set_texture_id(dot_id1);
    m_dot5 = new Lynton::TexQuad(m_renderer, m_camera, {20, 20, 1}, m_tex_lib->get_width(dot_id2), m_tex_lib->get_height(dot_id2));
    m_dot5->set_texture_id(dot_id1);
}

void SandboxLayer::update(double frame_time)
{
    // translate objects
    m_v_right += 200 * frame_time * (m_a_right - m_a_left);
    m_v_down += 200 * frame_time * (m_a_down - m_a_up);
    // m_v_right = 200000 * frame_time * (m_a_right - m_a_left);
    // m_v_down  = 200000 * frame_time * (m_a_down - m_a_up);
    m_camera->translate(m_v_right * frame_time, m_v_down * frame_time);

    // scale
    Lynton::scalar scale_factor = 1 / (1 + 3 * frame_time * (m_scale_up - m_scale_down));
    m_camera->scale_at(scale_factor, scale_factor, m_camera->get_middle());

    // rotate
    m_camera->rotate_at(90 * (m_rotate_right - m_rotate_left) * frame_time, m_camera->get_middle());

    // move dots
    m_dot1->set_location(m_camera->get_top_left());
    m_dot2->set_location(m_camera->get_top_right());
    m_dot3->set_location(m_camera->get_bottom_left());
    m_dot4->set_location(m_camera->get_bottom_right());
    m_dot5->set_location(m_camera->get_middle());
}

void SandboxLayer::render()
{
    m_smiley->render();
    // m_dot1->render();
    // m_dot2->render();
    // m_dot3->render();
    // m_dot4->render();
    // m_dot5->render();
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
            m_camera->flip_hor_at(m_camera->get_middle());
            return true;
        case SDLK_f:
            m_camera->flip_ver_at(m_camera->get_middle());
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
