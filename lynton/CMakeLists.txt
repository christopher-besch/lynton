cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(lynton ${SOURCES})
set(LYNTON_COMPILE_FLAGS "")
set(LYNTON_LINK_FLAGS "")

################
# dependencies #
################
# native build
if(NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  target_link_libraries(lynton PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
  target_include_directories(lynton PRIVATE ${SDL2_INCLUDE_DIR})
endif()

# emscripten
if(${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    set(LYNTON_COMPILE_FLAGS "${LYNTON_COMPILE_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]'")
    set(LYNTON_LINK_FLAGS "${LYNTON_COMPILE_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\", \"bmp\"]'")
endif()

#############
# resources #
#############
# copy in beginning
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/res" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
# copy before each build
add_custom_command(TARGET lynton PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/res"
    "${CMAKE_CURRENT_BINARY_DIR}/res")

# pack files with emscripten
if(${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  file(GLOB_RECURSE RES_FILES "${CMAKE_CURRENT_BINARY_DIR}/res/*")
  message("packing:")
  foreach(RES_FILE ${RES_FILES})
    message("\t${RES_FILE}")
    set(LYNTON_LINK_FLAGS "${LYNTON_LINK_FLAGS} --preload-file ${RES_FILE}")
  endforeach()
endif()

set_target_properties(lynton PROPERTIES COMPILE_FLAGS "${LYNTON_COMPILE_FLAGS}")
set_target_properties(lynton PROPERTIES LINK_FLAGS "${LYNTON_LINK_FLAGS}")
