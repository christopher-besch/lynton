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

SDL_Window* g_window = nullptr;
// surface is contained by window
SDL_Surface* g_screen_surface = nullptr;
// image loaded from disk
SDL_Surface* g_hello_world_img = nullptr;

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // location of window irrelevant
    g_window = SDL_CreateWindow("Lynton", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screeen_height, SDL_WINDOW_SHOWN);
    if (g_window == nullptr)
    {
        std::cout << "Windwo coudl not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // get window surface
    g_screen_surface = SDL_GetWindowSurface(g_window);
    return true;
}

// load splash image
bool load_media()
{
    g_hello_world_img = SDL_LoadBMP("images/hello_world.bmp");
    if (g_hello_world_img == nullptr)
    {
        std::cout << "Unable to load image "
                  << "images/hello_world.bmp"
                  << " SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void close()
{
    // deallocate surface
    SDL_FreeSurface(g_hello_world_img);
    g_hello_world_img = nullptr;

    // destroy window
    SDL_DestroyWindow(g_window);
    g_window = nullptr;

    // quit sdl subsystems
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (!init())
        raise_error("Failed to initialize!");
    if (!load_media())
        raise_error("Failed to lead media!");

    // apply image
    SDL_BlitSurface(g_hello_world_img, nullptr, g_screen_surface, nullptr);

    SDL_UpdateWindowSurface(g_window);

    SDL_Delay(2000);
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
