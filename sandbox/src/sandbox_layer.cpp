#include "sandbox_layer.h"

#include <iostream>

void SandboxLayer::start()
{
    Lynton::TextureLibrary* tex_lib = m_renderer->get_texture_library();

    unsigned short id = tex_lib->load_from_file("res/test.png");

    m_tex_quad = new Lynton::TexQuad(m_renderer, 20, 20, 500, 100);

    tex_lib->lock(id);
    uint32_t* pixels = static_cast<uint32_t*>(tex_lib->get_pixels(id));
    // 4 <- RGBA
    // -> gived amount of pixels per line
    int pixel_count = (tex_lib->get_pitch(id) / 4) * m_tex_quad->get_h();

    SDL_PixelFormat* mapping_format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

    for(int x = 0; x < tex_lib->get_h(id); ++x)
        for(int y = 0; y < tex_lib->get_w(id); ++y)
            if(x % 2 && y % 2)
                pixels[x + y * tex_lib->get_w(id)] = SDL_MapRGBA(mapping_format, 0x10, 0x50, 0xff, 0xff);

    tex_lib->unlock(id);
    SDL_FreeFormat(mapping_format);

    m_tex_quad->set_texture_id(id);
}

void SandboxLayer::update(double frame_time)
{
    log_client_extra("fps: {} frame time: {}", 1.0 / frame_time, frame_time);
}

void SandboxLayer::render()
{
    m_tex_quad->render();
}

bool SandboxLayer::handle_event(SDL_Event e)
{
    return false;
}
