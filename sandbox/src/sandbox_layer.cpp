#include "sandbox_layer.h"

#include <iostream>

SandboxLayer::~SandboxLayer()
{
    delete m_tex_quad1;
    delete m_tex_quad2;
}

void SandboxLayer::setup()
{
    m_tex_lib = m_renderer->get_texture_library();
    m_font    = new Lynton::Font("res/TruenoLight-E2pg.otf", 50);

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
    // update frame rate
    std::ostringstream buf;
    buf << "fps: " << (1.0 / frame_time);
    m_tex_lib->load_from_text(buf.str(), {0x00, 0xff, 0x10, 0xff}, m_font, m_tex_quad2->get_texture_id());

    // move objects
    // m_tex_quad1->translate(400 * frame_time, 400 * frame_time);
    // m_tex_quad1->rotate(90 * frame_time);
}

void SandboxLayer::render()
{
    m_tex_quad1->render();
    m_tex_quad2->render();
}

bool SandboxLayer::handle_event(SDL_Event e)
{
    if(e.type == SDL_KEYDOWN) {
        switch(e.key.keysym.sym) {
        case SDLK_w:
            m_tex_quad1->translate(0, -10);
            return true;
        case SDLK_s:
            m_tex_quad1->translate(0, 10);
            return true;
        case SDLK_a:
            m_tex_quad1->rotate(-10);
            return true;
        case SDLK_d:
            m_tex_quad1->rotate(10);
            return true;
        }
    }
    return false;
}
