cmake_minimum_required(VERSION 3.10)

project(lynton VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# emscripten setup
if(${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  set(CMAKE_C_FLAGS
      "${CMAKE_C_FLAGS}   -s EXIT_RUNTIME=1 -s ASYNCIFY_IMPORTS='[\"emscripten_force_exit\"]' -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]' -s ALLOW_MEMORY_GROWTH=1"
  )
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -s EXIT_RUNTIME=1 -s ASYNCIFY_IMPORTS='[\"emscripten_force_exit\"]' -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]' -s ALLOW_MEMORY_GROWTH=1"
  )
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

# native dependency setup
if(NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  find_package(SDL2 REQUIRED)
  find_package(SDL2_image REQUIRED)
  find_package(SDL2_ttf REQUIRED)
  find_package(OpenGL REQUIRED)
endif()

add_subdirectory("${CMAKE_SOURCE_DIR}/vendor/spdlog")
add_subdirectory("${CMAKE_SOURCE_DIR}/vendor/armadillo")
# imgui
add_library(imgui
    # main imgui files
    "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui.cpp"
    "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_demo.cpp"
    "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_draw.cpp"
    "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_tables.cpp"
    "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_widgets.cpp"
    # sdl2+opengl-specific files
    "${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_sdl.cpp"
    "${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp")
# Make sdl2 available to imgui
target_include_directories(imgui PUBLIC ${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})
# imgui/backends/ contains the sdl implementation
target_include_directories(imgui PUBLIC
    "${CMAKE_SOURCE_DIR}/vendor/imgui/"
    "${CMAKE_SOURCE_DIR}/vendor/imgui/backends/")
# configure imgui to use openggl through sdl2
target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_CUSTOM=<SDL_opengl.h>  GL_GLEXT_PROTOTYPES=1 IMGUI_IMPL_OPENGL_ES3=1)

# use warnings and multi threaded
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} /MP2 /DWIN32_LEAN_AND_MEAN /DNOMINMAX")
endif()

# binaries
add_subdirectory("${CMAKE_SOURCE_DIR}/lynton")
add_subdirectory("${CMAKE_SOURCE_DIR}/sandbox")
add_subdirectory("${CMAKE_SOURCE_DIR}/physics_words")
