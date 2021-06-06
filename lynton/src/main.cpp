#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_video.h>
#ifdef WASM
#include <emscripten.h>
#endif

#include "utils.h"

#include <SDL2/SDL.h>

#include <iostream>
#include <optional>
#include <stdlib.h>

constexpr int screen_width   = 640;
constexpr int screeen_height = 480;

int main(int argc, char* argv[])
{
    SDL_Window* window = nullptr;
    // surface is contained by window
    SDL_Surface* screen_surface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        raise_error("SDL could not initialize! SDL_Error: " << SDL_GetError());
    // location of window irrelevant
    window = SDL_CreateWindow("Lynton", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screeen_height, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        raise_error("Window coulr not be created! SDL_Error: " << SDL_GetError());

    screen_surface = SDL_GetWindowSurface(window);

    // fill surface white
    SDL_FillRect(screen_surface, nullptr, SDL_MapRGB(screen_surface->format, 0x00, 0xff, 0xff));

    // update surface
    SDL_UpdateWindowSurface(window);

#ifdef WASM
    // let the browser some time to render
    // use v sync
    // emscripten_set_main_loop(draw_random_pixels, 0, false);
#else
    // halt the entire program
    while (1)
    {
        // draw_random_pixels();
        SDL_Delay(16);
    }
#endif
    return 0;
}
