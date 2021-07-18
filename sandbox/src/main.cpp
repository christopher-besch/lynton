#include "lynton.h"
#include "sandbox_layer.h"

class Sandbox: public Lynton::Application {
public:
    Sandbox()
        : Application("Sandbox", 0, 960, 480)
    {
        add_layer(new SandboxLayer());
    }

    ~Sandbox() {}
};

Lynton::Application* Lynton::create_application()
{
    return new Sandbox();
}
