#include "core/application.h"
#include "pch.h"

// to be defined by client
extern Lynton::Application* Lynton::create_application();

int main()
{
    Lynton::Log::init();
    Lynton::Application* app = Lynton::create_application();

    // keeps running on native; immediately returns on emscripten
    app->run();

#ifndef __EMSCRIPTEN__
    delete app;
#endif
}
