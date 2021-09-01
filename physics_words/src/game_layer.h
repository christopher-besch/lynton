#pragma once

#include "lynton.h"
#include "quad.h"

class GameLayer: public Lynton::Layer {
public:
    GameLayer()
        : Layer("Game Layer") {}
    virtual ~GameLayer();
    void setup() override;

    // time in seconds since last fram
    void update(double frame_time) override;
    void render() override;

    // returns true if handled by this layer
    bool handle_event(SDL_Event e) override;

private:
    void create_square(Lynton::vec3 pos, Lynton::scalar size);

private:
    std::vector<Quad*>          m_squares;
    std::vector<unsigned short> m_color_ids;
};
