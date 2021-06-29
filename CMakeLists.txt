cmake_minimum_required(VERSION 3.10)

project(lynton VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# needed for sdl_ttf
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/freetype")
set(FREETYPE_LIBRARY "$<TARGET_FILE:freetype>")
set(FREETYPE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/vendor/freetype/include")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl_mixer")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl_image")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl_ttf")

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
