#include "lynton.h"

class Sandbox: public Lynton::Application {
public:
    Sandbox()
        : Application("Sandbox", 960, 480)
    {
        log_client_extra("hi");
    }

    ~Sandbox() {}
};

Lynton::Application* Lynton::create_application()
{
    return new Sandbox();
}
