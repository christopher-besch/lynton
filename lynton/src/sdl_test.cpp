#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <optional>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;

void draw_random_pixels()
{
    if (SDL_MUSTLOCK(surface))
        SDL_LockSurface(surface);

    uint8_t *pixels = static_cast<uint8_t *>(surface->pixels);

    for (int i = 0; i < 1048576; ++i)
    {
        char random_byte = rand() % 255;
        pixels[i] = random_byte;
    }

    if (SDL_MUSTLOCK(surface))
        SDL_UnlockSurface(surface);

    SDL_Texture *screen_texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screen_texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(screen_texture);
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);
    surface = SDL_CreateRGBSurface(0, 512, 512, 32, 0, 0, 0, 0);

#ifdef __EMSCRIPTEN__
    // let the browser some time to render
    // use v sync
    emscripten_set_main_loop(draw_random_pixels, 0, false);
#else
    // halt the entire program
    while (1)
    {
        draw_random_pixels();
        SDL_Delay(16);
    }
#endif
}
