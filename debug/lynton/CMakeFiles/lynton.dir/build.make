# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
include lynton/CMakeFiles/lynton.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lynton/CMakeFiles/lynton.dir/compiler_depend.make

# Include the progress variables for this target.
include lynton/CMakeFiles/lynton.dir/progress.make

# Include the compile flags for this target's objects.
include lynton/CMakeFiles/lynton.dir/flags.make

lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.cxx
lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -fpch-instantiate-templates -Xclang -emit-pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -x c++-header -MD -MT lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -MF CMakeFiles/lynton.dir/cmake_pch.hxx.pch.d -o CMakeFiles/lynton.dir/cmake_pch.hxx.pch -c /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.cxx

lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/cmake_pch.hxx.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -fpch-instantiate-templates -Xclang -emit-pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -x c++-header -E /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.cxx > CMakeFiles/lynton.dir/cmake_pch.hxx.i

lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/cmake_pch.hxx.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -fpch-instantiate-templates -Xclang -emit-pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -x c++-header -S /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.cxx -o CMakeFiles/lynton.dir/cmake_pch.hxx.s

lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o: ../lynton/src/core/application.cpp
lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -MD -MT lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o -MF CMakeFiles/lynton.dir/src/core/application.cpp.o.d -o CMakeFiles/lynton.dir/src/core/application.cpp.o -c /home/runner/work/lynton/lynton/lynton/src/core/application.cpp

lynton/CMakeFiles/lynton.dir/src/core/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/src/core/application.cpp.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -E /home/runner/work/lynton/lynton/lynton/src/core/application.cpp > CMakeFiles/lynton.dir/src/core/application.cpp.i

lynton/CMakeFiles/lynton.dir/src/core/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/src/core/application.cpp.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -S /home/runner/work/lynton/lynton/lynton/src/core/application.cpp -o CMakeFiles/lynton.dir/src/core/application.cpp.s

lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o: ../lynton/src/core/entry_point.cpp
lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -MD -MT lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o -MF CMakeFiles/lynton.dir/src/core/entry_point.cpp.o.d -o CMakeFiles/lynton.dir/src/core/entry_point.cpp.o -c /home/runner/work/lynton/lynton/lynton/src/core/entry_point.cpp

lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/src/core/entry_point.cpp.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -E /home/runner/work/lynton/lynton/lynton/src/core/entry_point.cpp > CMakeFiles/lynton.dir/src/core/entry_point.cpp.i

lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/src/core/entry_point.cpp.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -S /home/runner/work/lynton/lynton/lynton/src/core/entry_point.cpp -o CMakeFiles/lynton.dir/src/core/entry_point.cpp.s

lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o: ../lynton/src/core/layer.cpp
lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -MD -MT lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o -MF CMakeFiles/lynton.dir/src/core/layer.cpp.o.d -o CMakeFiles/lynton.dir/src/core/layer.cpp.o -c /home/runner/work/lynton/lynton/lynton/src/core/layer.cpp

lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/src/core/layer.cpp.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -E /home/runner/work/lynton/lynton/lynton/src/core/layer.cpp > CMakeFiles/lynton.dir/src/core/layer.cpp.i

lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/src/core/layer.cpp.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -S /home/runner/work/lynton/lynton/lynton/src/core/layer.cpp -o CMakeFiles/lynton.dir/src/core/layer.cpp.s

lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o: ../lynton/src/core/log.cpp
lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -MD -MT lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o -MF CMakeFiles/lynton.dir/src/core/log.cpp.o.d -o CMakeFiles/lynton.dir/src/core/log.cpp.o -c /home/runner/work/lynton/lynton/lynton/src/core/log.cpp

lynton/CMakeFiles/lynton.dir/src/core/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/src/core/log.cpp.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -E /home/runner/work/lynton/lynton/lynton/src/core/log.cpp > CMakeFiles/lynton.dir/src/core/log.cpp.i

lynton/CMakeFiles/lynton.dir/src/core/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/src/core/log.cpp.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -S /home/runner/work/lynton/lynton/lynton/src/core/log.cpp -o CMakeFiles/lynton.dir/src/core/log.cpp.s

lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o: ../lynton/src/renderer/renderable/texquad.cpp
lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -MD -MT lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o -MF CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o.d -o CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o -c /home/runner/work/lynton/lynton/lynton/src/renderer/renderable/texquad.cpp

lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -E /home/runner/work/lynton/lynton/lynton/src/renderer/renderable/texquad.cpp > CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.i

lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -S /home/runner/work/lynton/lynton/lynton/src/renderer/renderable/texquad.cpp -o CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.s

lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o: ../lynton/src/renderer/renderer.cpp
lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -MD -MT lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o -MF CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o.d -o CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o -c /home/runner/work/lynton/lynton/lynton/src/renderer/renderer.cpp

lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/src/renderer/renderer.cpp.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -E /home/runner/work/lynton/lynton/lynton/src/renderer/renderer.cpp > CMakeFiles/lynton.dir/src/renderer/renderer.cpp.i

lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/src/renderer/renderer.cpp.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -S /home/runner/work/lynton/lynton/lynton/src/renderer/renderer.cpp -o CMakeFiles/lynton.dir/src/renderer/renderer.cpp.s

lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o: ../lynton/src/renderer/texture/texture_library.cpp
lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -MD -MT lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o -MF CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o.d -o CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o -c /home/runner/work/lynton/lynton/lynton/src/renderer/texture/texture_library.cpp

lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -E /home/runner/work/lynton/lynton/lynton/src/renderer/texture/texture_library.cpp > CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.i

lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -S /home/runner/work/lynton/lynton/lynton/src/renderer/texture/texture_library.cpp -o CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.s

lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o: lynton/CMakeFiles/lynton.dir/flags.make
lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o: lynton/CMakeFiles/lynton.dir/includes_CXX.rsp
lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o: ../lynton/src/time/timer.cpp
lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx
lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o: lynton/CMakeFiles/lynton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -MD -MT lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o -MF CMakeFiles/lynton.dir/src/time/timer.cpp.o.d -o CMakeFiles/lynton.dir/src/time/timer.cpp.o -c /home/runner/work/lynton/lynton/lynton/src/time/timer.cpp

lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynton.dir/src/time/timer.cpp.i"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -E /home/runner/work/lynton/lynton/lynton/src/time/timer.cpp > CMakeFiles/lynton.dir/src/time/timer.cpp.i

lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynton.dir/src/time/timer.cpp.s"
	cd /home/runner/work/lynton/lynton/build/lynton && /home/runner/work/_temp/d87d3080-2b39-470d-8be2-9402638fb68f/emsdk-master/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/cmake_pch.hxx -S /home/runner/work/lynton/lynton/lynton/src/time/timer.cpp -o CMakeFiles/lynton.dir/src/time/timer.cpp.s

# Object files for target lynton
lynton_OBJECTS = \
"CMakeFiles/lynton.dir/src/core/application.cpp.o" \
"CMakeFiles/lynton.dir/src/core/entry_point.cpp.o" \
"CMakeFiles/lynton.dir/src/core/layer.cpp.o" \
"CMakeFiles/lynton.dir/src/core/log.cpp.o" \
"CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o" \
"CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o" \
"CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o" \
"CMakeFiles/lynton.dir/src/time/timer.cpp.o"

# External object files for target lynton
lynton_EXTERNAL_OBJECTS =

lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/cmake_pch.hxx.pch
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/src/core/application.cpp.o
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/src/core/entry_point.cpp.o
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/src/core/layer.cpp.o
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/src/core/log.cpp.o
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/src/renderer/renderable/texquad.cpp.o
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/src/renderer/renderer.cpp.o
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/src/renderer/texture/texture_library.cpp.o
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/src/time/timer.cpp.o
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/build.make
lynton/liblynton.a: lynton/CMakeFiles/lynton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/work/lynton/lynton/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library liblynton.a"
	cd /home/runner/work/lynton/lynton/build/lynton && $(CMAKE_COMMAND) -P CMakeFiles/lynton.dir/cmake_clean_target.cmake
	cd /home/runner/work/lynton/lynton/build/lynton && /usr/local/bin/cmake -E copy_directory /home/runner/work/lynton/lynton/lynton/res /home/runner/work/lynton/lynton/build/lynton/res
	cd /home/runner/work/lynton/lynton/build/lynton && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lynton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lynton/CMakeFiles/lynton.dir/build: lynton/liblynton.a
.PHONY : lynton/CMakeFiles/lynton.dir/build

lynton/CMakeFiles/lynton.dir/clean:
	cd /home/runner/work/lynton/lynton/build/lynton && $(CMAKE_COMMAND) -P CMakeFiles/lynton.dir/cmake_clean.cmake
.PHONY : lynton/CMakeFiles/lynton.dir/clean

lynton/CMakeFiles/lynton.dir/depend:
	cd /home/runner/work/lynton/lynton/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/lynton/lynton /home/runner/work/lynton/lynton/lynton /home/runner/work/lynton/lynton/build /home/runner/work/lynton/lynton/build/lynton /home/runner/work/lynton/lynton/build/lynton/CMakeFiles/lynton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lynton/CMakeFiles/lynton.dir/depend

