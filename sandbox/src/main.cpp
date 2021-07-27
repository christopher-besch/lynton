#include "debug_layer.h"
#include "lynton.h"
#include "sandbox_layer.h"

class Sandbox: public Lynton::Application {
public:
    Sandbox()
        : Application("Sandbox", 0, 600, 400)
    {
        add_layer(new SandboxLayer());
        add_overlay(new DebugLayer());
    }

    ~Sandbox() {}
};

Lynton::Application* Lynton::create_application()
{
    return new Sandbox();
}
