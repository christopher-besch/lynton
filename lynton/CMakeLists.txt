cmake_minimum_required(VERSION 3.10)

link_libraries(${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})

include_directories(${CMAKE_SOURCE_DIR}/include ${SDL2_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(lynton ${SOURCES})
