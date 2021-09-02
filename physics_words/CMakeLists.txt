cmake_minimum_required(VERSION  3.10)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(physics_words ${SOURCES})
set(PHYSICS_WORDS_COMPILER_FLAGS "")
set(PHYSICS_WORDS_LINK_FLAGS "")
target_include_directories(physics_words PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(physics_words PRIVATE lynton)

# ##############################################################################
# resources #
# ##############################################################################
# copy in beginning
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/res"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
# copy before each build
add_custom_command(
  TARGET physics_words
  PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/res"
          "${CMAKE_CURRENT_BINARY_DIR}/res")

# pack files with emscripten
if(${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  file(GLOB_RECURSE RES_FILES "${CMAKE_CURRENT_BINARY_DIR}/res/*")
  message("packing:")
  foreach(RES_FILE ${RES_FILES})
    message("\t${RES_FILE}")
    set(PHYSICS_WORDS_LINK_FLAGS "${PHYSICS_WORDS_LINK_FLAGS} --preload-file ${RES_FILE}")
  endforeach()
endif()

message("${PHYSICS_WORDS_COMPILER_FLAGS}")
message("${PHYSICS_WORDS_LINK_FLAGS}")
set_target_properties(physics_words PROPERTIES COMPILE_FLAGS "${PHYSICS_WORDS_COMPILER_FLAGS}")
set_target_properties(physics_words PROPERTIES LINK_FLAGS "${PHYSICS_WORDS_LINK_FLAGS}")
