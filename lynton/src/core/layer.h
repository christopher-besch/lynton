#pragma once

#include <SDL.h>
#include <string>

namespace Lynton {
class Layer {
public:
    Layer(const std::string& name);
    virtual ~Layer() = 0;

    virtual void update() = 0;
    virtual void render() = 0;

    // todo: replace with lynton wrapper event
    // returns true if handled by this layer
    virtual bool handle_event(SDL_Event) = 0;

private:
    std::string m_name;
};
} // namespace Lynton
