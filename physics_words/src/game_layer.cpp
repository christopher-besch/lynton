#include "game_layer.h"

#include "font.h"

#define AMOUNT_COLORS 50

GameLayer::~GameLayer()
{
    for(auto square: m_squares)
        delete square;
}

void GameLayer::setup()
{
    m_color_ids.reserve(AMOUNT_COLORS);
    for(int i = 0; i < AMOUNT_COLORS; ++i) {
        unsigned short id = m_tex_lib->create_blank(1, 1);
        m_tex_lib->lock(id);
        uint32_t* pixels = static_cast<uint32_t*>(m_tex_lib->get_pixels(id));
        pixels[0]        = m_renderer->get_color(m_random_gen->next<char>(), m_random_gen->next<char>(), m_random_gen->next<char>(), 0xff);
        m_tex_lib->unlock(id);

        m_color_ids.push_back(id);
    }
    // place blocks
    std::map<char, Char> chars         = load_font("res/font.txt");
    int                  char_height   = chars['a'].height;
    int                  screen_height = m_renderer->get_screen_height();
    int                  screen_width  = m_renderer->get_screen_width();

    std::vector<std::string> lines {
        "Hello World!",
        "How are",
        "you doing?",
    };
    Lynton::scalar ver_spacing {10};
    Lynton::scalar hor_spacing {1};
    // determine start height
    int last_y = screen_height -
                 lines.size() * char_height +
                 (lines.size() - 1) * ver_spacing;
    last_y /= 2;
    log_client_extra("y: {}", last_y);

    for(auto line: lines) {
        // how many pixels required by line
        int pixels {0};
        for(auto ch: line) {
            Char font_char {chars[ch]};
            pixels += font_char.width + font_char.spacing;
        }
        // determine start width
        int last_x = screen_width -
                     pixels +
                     (line.size() - 1) * hor_spacing;
        last_x /= 2;
        log_client_extra("x: {}", last_x);

        for(auto ch: line) {
            Char font_char {chars[ch]};
            for(auto pixel: font_char.pixels) {
                Lynton::scalar x = 11 * (last_x + pixel.first);
                Lynton::scalar y = 11 * (last_y + pixel.second);
                create_square({x, y, 1}, 10);
            }
            last_x += font_char.width + font_char.spacing;
        }
        last_y += char_height + ver_spacing;
    }
}

void GameLayer::update(double frame_time)
{
    for(auto square: m_squares)
        square->update(frame_time);
}

void GameLayer::render()
{
    for(auto square: m_squares)
        square->render();
}

bool GameLayer::handle_event(SDL_Event e)
{
    if(e.type == SDL_MOUSEBUTTONDOWN) {
        Lynton::vec3 source {static_cast<Lynton::scalar>(e.motion.x), static_cast<Lynton::scalar>(e.motion.y), 1};
        for(auto square: m_squares)
            square->repel(source, 1000);

        return true;
    }
    return false;
}

void GameLayer::create_square(Lynton::vec3 pos, Lynton::scalar size)
{
    Quad* quad = new Quad(m_renderer,
                          m_camera,
                          pos,
                          size,
                          size,
                          0.3,
                          m_color_ids[m_random_gen->next<int>(0, m_color_ids.size() - 1)]);
    m_squares.push_back(quad);
}
