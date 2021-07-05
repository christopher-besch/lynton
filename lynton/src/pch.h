#include "core/log.h"

#include <SDL.h>
#include <SDL_image.h>
#include <chrono>
#include <iostream>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <string>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
