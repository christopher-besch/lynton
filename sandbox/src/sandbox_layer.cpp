#include "sandbox_layer.h"

SandboxLayer::SandboxLayer()
    : Layer("Sandbox Layer") {}

void SandboxLayer::update(uint8_t ticks)
{
    log_client_extra("fps: {}", 1000.0f / ticks);
    log_client_extra("frame time: {}", ticks);
}

void SandboxLayer::render() {}

bool SandboxLayer::handle_event(SDL_Event e)
{
    return false;
}
