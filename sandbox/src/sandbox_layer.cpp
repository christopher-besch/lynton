#include "sandbox_layer.h"

SandboxLayer::SandboxLayer()
    : Layer("Sandbox Layer") {}

void SandboxLayer::update(double frame_time)
{
    log_client_extra("fps: {} frame time: {}", 1.0 / frame_time, frame_time);
}

void SandboxLayer::render() {}

bool SandboxLayer::handle_event(SDL_Event e)
{
    return false;
}
