#include "renderer.h"

#include "pch.h"

namespace Lynton {

Renderer::Renderer(const std::string& name, int screen_width, int screen_height, uint8_t r, uint8_t g, uint8_t b, RandomGen* random_gen)
    : m_name(name), m_screen_width(screen_width), m_screen_height(screen_height), m_r(r), m_g(g), m_b(b), m_random_gen(random_gen)
{
    log_lynton_general("Creating renderer for '{}'", m_name);
    // init
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        raise_critical("SDL could not initialize! SDL Error: {}", SDL_GetError());

    // set texture filtering to linear
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear"))
        log_lynton_warn("Linear texture filtering not enabled!");

    // create window
    m_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    if(m_window == nullptr)
        raise_critical("Window could not be created! SDL Error: {}", SDL_GetError());

    // create sdl renderer for window
    m_sdl_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if(m_sdl_renderer == nullptr)
        raise_critical("SDL renderer could not be created! SDL Error: {}", SDL_GetError());

    // init renderer color
    SDL_SetRenderDrawColor(m_sdl_renderer, 0x00, 0x00, 0x00, 0xff);

    // init png loading
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags))
        raise_critical("SDL_image could not initialize! SDL_image Error: {}", IMG_GetError());

    // init text loading
    if(TTF_Init() < 0)
        raise_critical("SDL_ttf could not initialize! SDL_ttf Error: {}", TTF_GetError());

    // used to own and handle textures
    m_texture_library = new TextureLibrary(m_sdl_renderer, m_random_gen);

    // used to create color
    m_mapping_format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

    // opengl setup
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_context = SDL_GL_CreateContext(m_window);

    // imgui setup
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    m_io = &ImGui::GetIO();
    // todo: let client decide style
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(m_window, m_context);
    ImGui_ImplOpenGL3_Init();
}

Renderer::~Renderer()
{
    log_lynton_general("Deleting renderer for '{}'", m_name);
    delete m_texture_library;

    // imgui shutdown
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    // sdl2 shutdown
    SDL_DestroyRenderer(m_sdl_renderer);
    SDL_DestroyWindow(m_window);
    SDL_FreeFormat(m_mapping_format);

    // quit sdl subsystems
    IMG_Quit();
    SDL_Quit();
}

void Renderer::clear()
{
    // set background
    // SDL_SetRenderDrawColor(m_sdl_renderer, m_r, m_g, m_b, 0xff);
    // SDL_RenderClear(m_sdl_renderer);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::set_viewport(int x, int y, int w, int h)
{
    SDL_Rect viewport {x, y, w, h};
    SDL_RenderSetViewport(m_sdl_renderer, &viewport);
}

void Renderer::create_imgui_frame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(m_window);
    ImGui::NewFrame();
}

void Renderer::update()
{
    ImGui::Render();
    glViewport(0, 0, (int)m_io->DisplaySize.x, (int)m_io->DisplaySize.y);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // ImGui::Render();
    // ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    // SDL_GL_SwapWindow(m_window);

    SDL_RenderPresent(m_sdl_renderer);
}

} // namespace Lynton
