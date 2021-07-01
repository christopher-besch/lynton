#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <optional>

#define raise_error(msg)                                                                                                  \
    do {                                                                                                                  \
        std::cerr << msg << " (in: " << __FILE__ << ":" << __LINE__ << "; in function: " << __func__ << ")" << std::endl; \
        std::exit(EXIT_FAILURE);                                                                                          \
    } while(0)

constexpr int screen_width  = 640;
constexpr int screen_height = 480;

enum class KeyPressSurfaces {
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
SDL_Texture* g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Total)];

SDL_Texture* g_current_surface = nullptr;

SDL_Renderer* g_renderer = nullptr;

void init()
{
    // init sdl
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        raise_error("SDL could not initialize! SDL Error: " << SDL_GetError());

    // location of window irrelevant
    g_window = SDL_CreateWindow("Lynton", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    if(g_window == nullptr)
        raise_error("Window could not be created! SDL Error: " << SDL_GetError());

    // init renderer
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    if(g_renderer == nullptr)
        raise_error("Renderer could not be created! SDL_Error: " << SDL_GetError());
    SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // init png loading
    int imgFlags = IMG_INIT_PNG;
    // check if result flag is desired
    if(!(IMG_Init(imgFlags) & imgFlags))
        raise_error("SDL_image could not initialize! SDL_image Error: " << IMG_GetError());

    // get window surface
    g_screen_surface = SDL_GetWindowSurface(g_window);
}

SDL_Texture* load_texture(std::string path)
{
    SDL_Texture* new_texture = nullptr;

    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == nullptr)
        raise_error("Unable to load image " << path << "! SDL_image Error: " << IMG_GetError());

    // create texture from surface pixels
    new_texture = SDL_CreateTextureFromSurface(g_renderer, loaded_surface);
    if(new_texture == nullptr)
        raise_error("Unable to create texture from " << path << "! SDL Error: " << SDL_GetError());

    SDL_FreeSurface(loaded_surface);

    return new_texture;
}

SDL_Surface* load_surface(std::string path)
{
    // load
    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == nullptr)
        raise_error("Unanble to load image '" << path << "'! SDL Error: " << SDL_GetError());

    // optimize color depth and resolution
    SDL_Surface* optimized_surface = SDL_LoadBMP(path.c_str());
    optimized_surface              = SDL_ConvertSurface(loaded_surface, g_screen_surface->format, 0);
    if(optimized_surface == NULL)
        raise_error("Unable to optimize image " << path << "! SDL Error: " << SDL_GetError());

    SDL_FreeSurface(loaded_surface);
    return optimized_surface;
}

void load_media()
{
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Default)] = load_texture("images/press.bmp");
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Up)]      = load_texture("images/up.bmp");
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Down)]    = load_texture("images/down.bmp");
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Left)]    = load_texture("images/left.bmp");
    g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Right)]   = load_texture("images/right.bmp");
}

void close()
{
    // deallocate surfaces
    for(int i = 0; i < static_cast<long>(KeyPressSurfaces::Total); ++i) {
        SDL_DestroyTexture(g_key_press_surfaces[i]);
        g_key_press_surfaces[i] = nullptr;
    }

    // destroy window
    SDL_DestroyWindow(g_window);
    g_window = nullptr;

    // quit sdl subsystems
    SDL_Quit();
}

struct RunObj {
    bool quit = false;
    // event handler
    SDL_Event e;
};

void draw(void* run_obj)
{
    RunObj* r = static_cast<RunObj*>(run_obj);
    while(SDL_PollEvent(&r->e) != 0) {
        if(r->e.type == SDL_QUIT)
            r->quit = true;
        else if(r->e.type == SDL_KEYDOWN) {
            switch(r->e.key.keysym.sym) {
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
    SDL_Rect stretch_rect;
    stretch_rect.x = 0;
    stretch_rect.y = 0;
    stretch_rect.w = screen_width / 2;
    stretch_rect.h = screen_height / 2;

    SDL_RenderClear(g_renderer);

    // render texture to screen
    SDL_RenderCopy(g_renderer, g_current_surface, NULL, NULL);

    // update screen
    SDL_RenderPresent(g_renderer);

    // for bliting a surface instead
    // SDL_BlitSurface(g_current_surface, nullptr, g_screen_surface, nullptr);
    // SDL_BlitScaled(g_current_surface, nullptr, g_screen_surface, &stretch_rect);
    // SDL_UpdateWindowSurface(g_window);
}

int main(int argc, char* argv[])
{
    std::cout << "hello world" << std::endl;
    init();
    load_media();

    g_current_surface = g_key_press_surfaces[static_cast<long>(KeyPressSurfaces::Default)];
    RunObj run_obj;

#ifdef __EMSCRIPTEN__
    // let the browser some time to render
    // use v-sync
    emscripten_set_main_loop_arg(draw, &run_obj, 0, true);
#else
    // halt the entire program
    while(1) {
        draw(&run_obj);
        SDL_Delay(1 / 60);
    }
#endif
    close();
}
