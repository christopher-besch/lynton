# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/work/lynton/lynton

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/work/lynton/lynton/build

# Include any dependencies generated for this target.
include sandbox/CMakeFiles/sandbox.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include sandbox/CMakeFiles/sandbox.dir/compiler_depend.make

# Include the progress variables for this target.
include sandbox/CMakeFiles/sandbox.dir/progress.make

# Include the compile flags for this target's objects.
include sandbox/CMakeFiles/sandbox.dir/flags.make

sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.o: sandbox/CMakeFiles/sandbox.dir/flags.make
sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.o: sandbox/CMakeFiles/sandbox.dir/includes_CXX.rsp
sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.o: ../sandbox/src/debug_layer.cpp
sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.o: sandbox/CMakeFiles/sandbox.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.o"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.o -MF CMakeFiles/sandbox.dir/src/debug_layer.cpp.o.d -o CMakeFiles/sandbox.dir/src/debug_layer.cpp.o -c /home/runner/work/lynton/lynton/sandbox/src/debug_layer.cpp

sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sandbox.dir/src/debug_layer.cpp.i"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/lynton/lynton/sandbox/src/debug_layer.cpp > CMakeFiles/sandbox.dir/src/debug_layer.cpp.i

sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sandbox.dir/src/debug_layer.cpp.s"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/lynton/lynton/sandbox/src/debug_layer.cpp -o CMakeFiles/sandbox.dir/src/debug_layer.cpp.s

sandbox/CMakeFiles/sandbox.dir/src/main.cpp.o: sandbox/CMakeFiles/sandbox.dir/flags.make
sandbox/CMakeFiles/sandbox.dir/src/main.cpp.o: sandbox/CMakeFiles/sandbox.dir/includes_CXX.rsp
sandbox/CMakeFiles/sandbox.dir/src/main.cpp.o: ../sandbox/src/main.cpp
sandbox/CMakeFiles/sandbox.dir/src/main.cpp.o: sandbox/CMakeFiles/sandbox.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object sandbox/CMakeFiles/sandbox.dir/src/main.cpp.o"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sandbox/CMakeFiles/sandbox.dir/src/main.cpp.o -MF CMakeFiles/sandbox.dir/src/main.cpp.o.d -o CMakeFiles/sandbox.dir/src/main.cpp.o -c /home/runner/work/lynton/lynton/sandbox/src/main.cpp

sandbox/CMakeFiles/sandbox.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sandbox.dir/src/main.cpp.i"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/lynton/lynton/sandbox/src/main.cpp > CMakeFiles/sandbox.dir/src/main.cpp.i

sandbox/CMakeFiles/sandbox.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sandbox.dir/src/main.cpp.s"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/lynton/lynton/sandbox/src/main.cpp -o CMakeFiles/sandbox.dir/src/main.cpp.s

sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o: sandbox/CMakeFiles/sandbox.dir/flags.make
sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o: sandbox/CMakeFiles/sandbox.dir/includes_CXX.rsp
sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o: ../sandbox/src/sandbox_layer.cpp
sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o: sandbox/CMakeFiles/sandbox.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o -MF CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o.d -o CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o -c /home/runner/work/lynton/lynton/sandbox/src/sandbox_layer.cpp

sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.i"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/lynton/lynton/sandbox/src/sandbox_layer.cpp > CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.i

sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.s"
	cd /home/runner/work/lynton/lynton/build/sandbox && /home/runner/work/_temp/bc3298c7-72b1-4c84-bfaf-5b656801c2df/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/lynton/lynton/sandbox/src/sandbox_layer.cpp -o CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.s

# Object files for target sandbox
sandbox_OBJECTS = \
"CMakeFiles/sandbox.dir/src/debug_layer.cpp.o" \
"CMakeFiles/sandbox.dir/src/main.cpp.o" \
"CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o"

# External object files for target sandbox
sandbox_EXTERNAL_OBJECTS =

sandbox/sandbox.html: sandbox/CMakeFiles/sandbox.dir/src/debug_layer.cpp.o
sandbox/sandbox.html: sandbox/CMakeFiles/sandbox.dir/src/main.cpp.o
sandbox/sandbox.html: sandbox/CMakeFiles/sandbox.dir/src/sandbox_layer.cpp.o
sandbox/sandbox.html: sandbox/CMakeFiles/sandbox.dir/build.make
sandbox/sandbox.html: lynton/liblynton.a
sandbox/sandbox.html: vendor/spdlog/libspdlog.a
sandbox/sandbox.html: vendor/armadillo/libarmadillo.a
sandbox/sandbox.html: sandbox/CMakeFiles/sandbox.dir/linklibs.rsp
sandbox/sandbox.html: sandbox/CMakeFiles/sandbox.dir/objects1.rsp
sandbox/sandbox.html: sandbox/CMakeFiles/sandbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sandbox.html"
	cd /home/runner/work/lynton/lynton/build/sandbox && /usr/local/bin/cmake -E copy_directory /home/runner/work/lynton/lynton/sandbox/res /home/runner/work/lynton/lynton/build/sandbox/res
	cd /home/runner/work/lynton/lynton/build/sandbox && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sandbox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sandbox/CMakeFiles/sandbox.dir/build: sandbox/sandbox.html
.PHONY : sandbox/CMakeFiles/sandbox.dir/build

sandbox/CMakeFiles/sandbox.dir/clean:
	cd /home/runner/work/lynton/lynton/build/sandbox && $(CMAKE_COMMAND) -P CMakeFiles/sandbox.dir/cmake_clean.cmake
.PHONY : sandbox/CMakeFiles/sandbox.dir/clean

sandbox/CMakeFiles/sandbox.dir/depend:
	cd /home/runner/work/lynton/lynton/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/lynton/lynton /home/runner/work/lynton/lynton/sandbox /home/runner/work/lynton/lynton/build /home/runner/work/lynton/lynton/build/sandbox /home/runner/work/lynton/lynton/build/sandbox/CMakeFiles/sandbox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sandbox/CMakeFiles/sandbox.dir/depend

