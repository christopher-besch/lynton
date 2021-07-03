cmake_minimum_required(VERSION 3.10)

if(!EMSCRIPTEN)
  link_libraries(${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
  include_directories(${CMAKE_SOURCE_DIR}/include ${SDL2_INCLUDE_DIR})
endif()

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(lynton ${SOURCES})

set(GLOB_RECURSE EMSCRIPTEN_FILES "${CMAKE_CURRENT_BINARY_DIR}/images")
foreach(EMSCRIPTEN_FILE ${EMSCRIPTEN_FILES})
  message("${EMSCRIPTEN_FILE}")
  set_target_properties(lynton PROPERTIES LINK_FLAGS
                                          "--preload-file ${EMSCRIPTEN_FILE}")
endforeach()

set_target_properties(
  lynton
  PROPERTIES
    LINK_FLAGS
    "--preload-file ${CMAKE_CURRENT_BINARY_DIR}/images/press.bmp --preload-file ${CMAKE_CURRENT_BINARY_DIR}/images/left.bmp --preload-file ${CMAKE_CURRENT_BINARY_DIR}/images/left.bmp --preload-file ${CMAKE_CURRENT_BINARY_DIR}/images/right.bmp --preload-file ${CMAKE_CURRENT_BINARY_DIR}/images/up.bmp --preload-file ${CMAKE_CURRENT_BINARY_DIR}/images/down.bmp"
)
