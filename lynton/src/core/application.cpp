#include "application.h"

#include "pch.h"

namespace Lynton {
Application::Application(const std::string& name)
    : m_name(name) {};

Application::~Application() {}
void Application::run() {}
} // namespace Lynton
