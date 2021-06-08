#ifdef WASM
#include <emscripten.h>
#endif

#include "pch.h"

#include <iostream>
#include <optional>

constexpr int screen_width   = 640;
constexpr int screeen_height = 480;

enum class KeyPressSurfaces
{
    Default,
    Up,
    Down,
    Left,
    Right,
    Total,
};

SDL_Window* g_window = nullptr;
// surface is contained by window
SDL_Surface* g_screen_surface = nullptr;

// one image for each key
SDL_Surface* g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Total)];

SDL_Surface* g_current_surface = nullptr;

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        raise_error("SDL could not initialize! SDL Error: " << SDL_GetError());

    // location of window irrelevant
    g_window = SDL_CreateWindow("Lynton", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screeen_height, SDL_WINDOW_SHOWN);
    if (g_window == nullptr)
        raise_error("Windwo coudl not be created! SDL Error: " << SDL_GetError());

    // get window surface
    g_screen_surface = SDL_GetWindowSurface(g_window);
}

SDL_Surface* load_surface(std::string path)
{
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());
    if (surface == nullptr)
        raise_error("Unanble to load image '" << path << "'! SDL Error: " << SDL_GetError() << std::endl);
    return surface;
}

void load_media()
{
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Default)] = load_surface("images/press.bmp");
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Up)]      = load_surface("images/up.bmp");
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Down)]    = load_surface("images/down.bmp");
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Left)]    = load_surface("images/left.bmp");
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Right)]   = load_surface("images/right.bmp");
}

void close()
{
    // deallocate surfaces
    for (int i = 0; i < static_cast<long>(KeyPressSurfaces::Total); ++i)
    {
        SDL_FreeSurface(g_key_press_surfaces[i]);
        g_key_press_surfaces[i] = nullptr;
    }

    // destroy window
    SDL_DestroyWindow(g_window);
    g_window = nullptr;

    // quit sdl subsystems
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    init();
    load_media();

    bool quit = false;
    // event handler
    SDL_Event e;

    g_current_surface = g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Default)];

    // this is art; don't touch
    while (!(((quit == true) == false) == false))
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    g_current_surface = g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Up)];
                    break;
                case SDLK_DOWN:
                    g_current_surface = g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Down)];
                    break;
                case SDLK_LEFT:
                    g_current_surface = g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Left)];
                    break;
                case SDLK_RIGHT:
                    g_current_surface = g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Right)];
                    break;
                default:
                    g_current_surface = g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Default)];
                }
            }
        }

        // apply image
        SDL_BlitSurface(g_current_surface, nullptr, g_screen_surface, nullptr);
        SDL_UpdateWindowSurface(g_window);
    }
    close();

    // #ifdef WASM
    //     // let the browser some time to render
    //     // use v sync
    //     // emscripten_set_main_loop(draw_random_pixels, 0, false);
    // #else
    //     // halt the entire program
    //     while (1)
    //     {
    //         // draw_random_pixels();
    //         SDL_Delay(16);
    //     }
    // #endif
    return 0;
}
