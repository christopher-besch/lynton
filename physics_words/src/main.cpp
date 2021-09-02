#include "debug_layer.h"
#include "game_layer.h"
#include "lynton.h"

class PhysicsWords: public Lynton::Application {
public:
    PhysicsWords()
        : Application("Physics Words", 0, 1500, 900)
    {
        add_layer(new GameLayer());
        add_overlay(new DebugLayer());
    }
    ~PhysicsWords() {}
};

Lynton::Application* Lynton::create_application()
{
    return new PhysicsWords();
}
