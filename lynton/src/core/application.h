#pragma once

#include "core/layer.h"
#include "renderer/renderer.h"

#include <string>
#include <vector>

namespace Lynton {
class Application {
public:
    Application(const std::string& name, int screen_width, int screen_height);
    virtual ~Application();

    void run();

private:
    std::string         m_name;
    Renderer*           m_renderer = nullptr;
    std::vector<Layer*> m_layers;
};

// to be defined by client
Application* create_application();
} // namespace Lynton
