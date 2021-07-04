cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(sandbox ${SOURCES})
set(SANDBOX_COMPILE_FLAGS "")
set(SANDBOX_LINK_FLAGS "")
target_include_directories(sandbox PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(sandbox PRIVATE lynton)

# ##############################################################################
# resources #
# ##############################################################################
# copy in beginning
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/res"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
# copy before each build
add_custom_command(
  TARGET sandbox
  PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/res"
          "${CMAKE_CURRENT_BINARY_DIR}/res")

# pack files with emscripten
if(${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  file(GLOB_RECURSE RES_FILES "${CMAKE_CURRENT_BINARY_DIR}/res/*")
  message("packing:")
  foreach(RES_FILE ${RES_FILES})
    message("\t${RES_FILE}")
    set(SANDBOX_LINK_FLAGS "${SANDBOX_LINK_FLAGS} --preload-file ${RES_FILE}")
  endforeach()
endif()

set_target_properties(sandbox PROPERTIES COMPILE_FLAGS
                                         "${SANDBOX_COMPILE_FLAGS}")
set_target_properties(sandbox PROPERTIES LINK_FLAGS "${SANDBOX_LINK_FLAGS}")
