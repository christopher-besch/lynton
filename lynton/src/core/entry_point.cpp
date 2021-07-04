#include "core/application.h"
#include "pch.h"

// to be defined by client
extern Lynton::Application* Lynton::create_application();

int main(int argc, char* argv[])
{
    Lynton::Log::init();
    Lynton::Application* app = Lynton::create_application();

    app->run();

    delete app;
}
