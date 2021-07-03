cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(lynton ${SOURCES})
set(LYNTON_COMPILE_FLAGS "")
set(LYNTON_LINK_FLAGS "")

################
# dependencies #
################
# native build
if(!EMSCRIPTEN)
  target_link_libraries(lynton PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
  target_include_directories(lynton PRIVATE ${SDL2_INCLUDE_DIR})
endif()

# emscripten
if(EMSCRIPTEN)
    set(LYNTON_COMPILE_FLAGS "${LYNTON_COMPILE_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]'")
endif()

#############
# resources #
#############
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/res" DESTINATION "${CMAKE_BINARY_DIR}/res")

# pack files for emscripten
if(EMSCRIPTEN)
  set(GLOB_RECURSE EMSCRIPTEN_FILES "${CMAKE_BINARY_DIR}/res")
  foreach(EMSCRIPTEN_FILE ${EMSCRIPTEN_FILES})
    message("${EMSCRIPTEN_FILE}")
    set_target_properties(lynton PROPERTIES LINK_FLAGS
                                          "--preload-file ${EMSCRIPTEN_FILE}")
  endforeach()
  set_target_properties(lynton PROPERTIES LINK_FLAGS "${LYNTON_LINK_FLAGS}")
endif()
