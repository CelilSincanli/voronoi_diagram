# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/celil/workspace/voronoi_diagram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/celil/workspace/voronoi_diagram/build

# Include any dependencies generated for this target.
include CMakeFiles/voronoi_diagram.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/voronoi_diagram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/voronoi_diagram.dir/flags.make

CMakeFiles/voronoi_diagram.dir/src/main.cpp.o: CMakeFiles/voronoi_diagram.dir/flags.make
CMakeFiles/voronoi_diagram.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/celil/workspace/voronoi_diagram/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/voronoi_diagram.dir/src/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/voronoi_diagram.dir/src/main.cpp.o -c /home/celil/workspace/voronoi_diagram/src/main.cpp

CMakeFiles/voronoi_diagram.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voronoi_diagram.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/celil/workspace/voronoi_diagram/src/main.cpp > CMakeFiles/voronoi_diagram.dir/src/main.cpp.i

CMakeFiles/voronoi_diagram.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voronoi_diagram.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/celil/workspace/voronoi_diagram/src/main.cpp -o CMakeFiles/voronoi_diagram.dir/src/main.cpp.s

# Object files for target voronoi_diagram
voronoi_diagram_OBJECTS = \
"CMakeFiles/voronoi_diagram.dir/src/main.cpp.o"

# External object files for target voronoi_diagram
voronoi_diagram_EXTERNAL_OBJECTS =

voronoi_diagram: CMakeFiles/voronoi_diagram.dir/src/main.cpp.o
voronoi_diagram: CMakeFiles/voronoi_diagram.dir/build.make
voronoi_diagram: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
voronoi_diagram: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
voronoi_diagram: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
voronoi_diagram: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
voronoi_diagram: CMakeFiles/voronoi_diagram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/celil/workspace/voronoi_diagram/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable voronoi_diagram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/voronoi_diagram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/voronoi_diagram.dir/build: voronoi_diagram

.PHONY : CMakeFiles/voronoi_diagram.dir/build

CMakeFiles/voronoi_diagram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/voronoi_diagram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/voronoi_diagram.dir/clean

CMakeFiles/voronoi_diagram.dir/depend:
	cd /home/celil/workspace/voronoi_diagram/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/celil/workspace/voronoi_diagram /home/celil/workspace/voronoi_diagram /home/celil/workspace/voronoi_diagram/build /home/celil/workspace/voronoi_diagram/build /home/celil/workspace/voronoi_diagram/build/CMakeFiles/voronoi_diagram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/voronoi_diagram.dir/depend

