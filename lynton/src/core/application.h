#pragma once

#include <string>

namespace Lynton {
class Application {
public:
    Application(const std::string& name = "Lynton App");
    virtual ~Application();

    void run();

private:
    std::string m_name;
};

// to be defined by client
Application* create_application();
} // namespace Lynton
