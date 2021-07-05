#include "application.h"

#include "pch.h"

namespace Lynton {
Application::Application(const std::string& name, int screen_width, int screen_height)
    : m_name(name), m_renderer(new Renderer(name, screen_width, screen_height))
{
    log_lynton_extra("Creating application '{}'", m_name);
}

Application::~Application()
{
    log_lynton_extra("Deleting application '{}'", m_name);
    delete m_renderer;
    for(Layer* layer: m_layers)
        delete layer;
}

void Application::run()
{
    bool      quit = false;
    SDL_Event e;

    while(!quit) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT)
                quit = true;
            else {
                // go through all layers, stop when handled
                for(auto i = m_layers.begin(); i < m_layers.end(); ++i)
                    if(!(*i)->handle_event(e))
                        break;
            }
        }
        m_renderer->clear();
        // todo: add timing
        for(auto i = m_layers.begin(); i < m_layers.end(); ++i) {
            (*i)->update();
            (*i)->render();
        }
        m_renderer->update();
    }
}
} // namespace Lynton
