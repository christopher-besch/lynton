#include "sandbox_layer.h"

void SandboxLayer::start()
{
    Lynton::TextureLibrary* texture_library = m_renderer->get_texture_library();

    unsigned short id = texture_library->load_from_file("test.png");
    log_client_error("{}", id);

    m_tex_quad = new Lynton::TexQuad(m_renderer, 20, 20);
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
