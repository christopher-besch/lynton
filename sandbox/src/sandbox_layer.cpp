#include "sandbox_layer.h"

#include <iostream>

SandboxLayer::~SandboxLayer()
{
    delete m_tex_quad1;
    delete m_tex_quad2;
}

void SandboxLayer::setup()
{
    Lynton::TextureLibrary* tex_lib = m_renderer->get_texture_library();

    // image
    unsigned short img_id = tex_lib->load_from_file("res/test.png");

    tex_lib->lock(img_id);
    uint32_t* pixels = static_cast<uint32_t*>(tex_lib->get_pixels(img_id));
    // 4 <- RGBA
    // -> gived amount of pixels per line
    int pixel_count = (tex_lib->get_pitch(img_id) / 4) * tex_lib->get_h(img_id);

    SDL_PixelFormat* mapping_format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

    for(int x = 0; x < tex_lib->get_h(img_id); ++x)
        for(int y = 0; y < tex_lib->get_w(img_id); ++y)
            if(x % 2 && y % 2)
                pixels[x + y * tex_lib->get_w(img_id)] = SDL_MapRGBA(mapping_format, 0x10, 0x50, 0xff, 0xff);

    tex_lib->unlock(img_id);
    SDL_FreeFormat(mapping_format);

    // text
    Lynton::Font*  font    = new Lynton::Font("res/TruenoLight-E2pg.otf", 50);
    unsigned short text_id = tex_lib->load_from_text("Hello World!", {0xff, 0x20, 0x20, 0xff}, font);

    m_tex_quad1 = new Lynton::TexQuad(m_renderer, {20, 20}, {600, 400});
    m_tex_quad1->set_texture_id(img_id);

    m_tex_quad2 = new Lynton::TexQuad(m_renderer, {20, 20}, tex_lib->get_scale(text_id));
    m_tex_quad2->set_texture_id(text_id);
}

void SandboxLayer::update(double frame_time)
{
    // log_client_extra("fps: {} frame time: {}", 1.0 / frame_time, frame_time);
}

void SandboxLayer::render()
{
    m_tex_quad1->render();
    m_tex_quad2->render();
}

bool SandboxLayer::handle_event(SDL_Event e)
{
    return false;
}
