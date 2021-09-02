#pragma once

#include "core/layer.h"
#include "core/random.h"
#include "renderer/renderer.h"
#include "time/timer.h"

#include <string>
#include <vector>

namespace Lynton {
class Application {
public:
    // use goal_fps = 0 for vsync (emscripten) or uncapped (native)
    Application(const std::string& name, int goal_fps, int screen_width, int screen_height, uint8_t r=0x70, uint8_t g=0x70, uint8_t b=0x70);
    virtual ~Application();

    void setup_layer(Layer* layer);
    // takes ownership of layer
    // adds below other layers
    void add_layer(Layer* layer);
    // takes ownership of layer
    // adds above other layers
    void add_overlay(Layer* layer);

    // from start to end
    // keeps running on native; immediately returns on emscripten
    void run();
    // single frame
    void run_frame();

protected:
    RandomGen* m_random_gen = nullptr;
    bool       m_quit       = false;

private:
    std::string         m_name;
    int                 m_goal_fps;
    double              m_goal_frame_time;
    Renderer*           m_renderer = nullptr;
    std::vector<Layer*> m_layers;

    SDL_Event m_e;
    Timer     m_main_loop_timer;
};

// to be defined by client
Application* create_application();
} // namespace Lynton
