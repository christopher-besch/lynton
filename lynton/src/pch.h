#define GL_GLEXT_PROTOTYPES
#include "core/log.h"
#include "core/random.h"
#include "math/defs.h"
#include "math/matrices.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include <armadillo>
#include <chrono>
#include <cmath>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>
#include <iostream>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <string>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
