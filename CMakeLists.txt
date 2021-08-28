cmake_minimum_required(VERSION 3.10)

project(lynton VERSION 0.1)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.16/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

set(CONAN_LIBRARIES sdl/2.0.16 sdl_ttf/2.0.15 sdl2_image/2.0.5@bincrafters/stable)

set(CONAN_OPTIONS sdl:sdl2main=False)

conan_add_remote(
        NAME
        conan-center
        URL
        https://conan.bintray.com)

conan_add_remote(
    NAME
    bincrafters
    URL
    https://bincrafters.jfrog.io/artifactory/api/conan/public-conan)

conan_cmake_run(
        REQUIRES
        ${CONAN_LIBRARIES}
        OPTIONS
        ${CONAN_OPTIONS}
        BASIC_SETUP
        CMAKE_TARGETS
        BUILD
        missing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# native dependency setup
# if(NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
#   find_package(SDL2 REQUIRED)
#   find_package(SDL2_image REQUIRED)
#   find_package(SDL2_ttf REQUIRED)
# endif()

add_subdirectory("${CMAKE_SOURCE_DIR}/vendor/spdlog")
add_subdirectory("${CMAKE_SOURCE_DIR}/vendor/armadillo")

# emscripten setup
if(${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  set(CMAKE_C_FLAGS
      "${CMAKE_C_FLAGS}   -s EXIT_RUNTIME=1 -s ASYNCIFY_IMPORTS='[\"emscripten_force_exit\"]' -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]'"
  )
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -s EXIT_RUNTIME=1 -s ASYNCIFY_IMPORTS='[\"emscripten_force_exit\"]' -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]'"
  )
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

# binaries
add_subdirectory("${CMAKE_SOURCE_DIR}/lynton")
add_subdirectory("${CMAKE_SOURCE_DIR}/sandbox")
