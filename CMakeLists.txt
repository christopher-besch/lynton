cmake_minimum_required(VERSION 3.10)

project(lynton VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# needed for sdl_ttf
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/freetype")
# set(FREETYPE_INCLUDE_DIRS
# "${CMAKE_CURRENT_SOURCE_DIR}/vendor/freetype/include") set(FREETYPE_LIBRARY
# freetype)

# set(TTF_WITH_HARFBUZZ ON BOOL)
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl_mixer")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl_image")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl_ttf")

if(!EMSCRIPTEN)
  find_package(SDL2 REQUIRED)
  find_package(SDL2_image REQUIRED)
  find_package(SDL2_ttf REQUIRED)
endif()

# emscripten setup
if(EMSCRIPTEN)
  set(CMAKE_C_FLAGS
      "${CMAKE_C_FLAGS}   -s ASSERTIONS=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]' -s WASM=1 -s ASYNCIFY"
  )
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -s ASSERTIONS=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]' -s WASM=1 -s ASYNCIFY"
  )

  # accessible files file(GLOB_RECURSE EMSCRIPTEN_FILES
  # "${CMAKE_CURRENT_BINARY_DIR}/images/*")
  set(GLOB_RECURSE EMSCRIPTEN_FILES
                   "down.bmp;left.bmp;right.bmp;up.bmp;press.bmp")
  foreach(EMSCRIPTEN_FILE ${EMSCRIPTEN_FILES})
    message("${EMSCRIPTEN_FILE}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}     --preload-file ${EMSCRIPTEN_FILE}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --preload-file ${EMSCRIPTEN_FILE}")
  endforeach()

  set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

# use warnings and multi threaded
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} /MP2 /DWIN32_LEAN_AND_MEAN /DNOMINMAX")
endif()

# executables
add_subdirectory("${CMAKE_SOURCE_DIR}/lynton")
