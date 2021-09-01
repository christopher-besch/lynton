#include "debug_layer.h"
#include "game_layer.h"
#include "lynton.h"

class PhysicsWords: public Lynton::Application {
public:
    PhysicsWords()
        : Application("Physics Words", 0, 900, 600)
    {
        add_layer(new GameLayer());
#ifndef NDEBUG
        add_overlay(new DebugLayer());
#endif
    }
    ~PhysicsWords() {}
};

Lynton::Application* Lynton::create_application()
{
    return new PhysicsWords();
}
