#include "application.h"

#include "pch.h"
#include "time/timer.h"

namespace Lynton {
Application::Application(const std::string& name, int goal_fps, int screen_width, int screen_height)
    : m_name(name),
      m_goal_fps(goal_fps),
      m_goal_frame_time(goal_fps ? 1.0 / goal_fps : 0.0),
      m_renderer(new Renderer(name, screen_width, screen_height))
{
    log_lynton_general("Creating application '{}'", m_name);
}

Application::~Application()
{
    log_lynton_general("Deleting application '{}'", m_name);
    delete m_renderer;
    for(Layer* layer: m_layers)
        delete layer;
}

void Application::run()
{
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg([](void* app) { static_cast<Application*>(app)->run_frame(); }, this, m_goal_fps, false);
#else
    while(!m_quit) {
        run_frame();

        // wait if required
        double sleep_time = m_goal_frame_time - m_main_loop_timer.get_time();
        if(sleep_time > 0)
            SDL_Delay(1000 * sleep_time);
    }
#endif
}

void Application::run_frame()
{
    // time since last frame
    double ticks = m_main_loop_timer.get_time();
    m_main_loop_timer.reset();

    // handle events
    while(SDL_PollEvent(&m_e)) {
        if(m_e.type == SDL_QUIT)
            m_quit = true;
        else
            // go through all layers, stop when handled
            for(auto i = m_layers.begin(); i < m_layers.end(); ++i)
                if(!(*i)->handle_event(m_e))
                    break;
    }

    // update
    for(auto i = m_layers.begin(); i < m_layers.end(); ++i)
        (*i)->update(ticks);

    // render
    m_renderer->clear();
    for(auto i = m_layers.begin(); i < m_layers.end(); ++i)
        (*i)->render();
    m_renderer->update();
}

} // namespace Lynton
