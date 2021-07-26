#include "debug_layer.h"

DebugLayer::~DebugLayer()
{
    delete m_fps_quad;
}

void DebugLayer::setup()
{
    m_font = new Lynton::Font("res/iosevka-extendedbold.ttf", 90);

    // text
    unsigned short text_id = m_tex_lib->load_from_text("1234", {0xff, 0x20, 0x20, 0xff}, m_font);

    m_fps_quad = new Lynton::TexQuad(m_renderer, m_camera, {10, 10, 1}, m_tex_lib->get_width(text_id), m_tex_lib->get_height(text_id));
    m_fps_quad->set_texture_id(text_id);
}

void DebugLayer::update(double frame_time)
{
    // update frame rate
    char str[20];
    sprintf(str, "%4.0f", 1.0 / frame_time);
    m_tex_lib->load_from_text(str, {0x00, 0xff, 0x10, 0xff}, m_font, m_fps_quad->get_texture_id());
}

void DebugLayer::render()
{
    // m_fps_quad->render();
}

bool DebugLayer::handle_event(SDL_Event e)
{
    return false;
}
