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
CMAKE_SOURCE_DIR = /home/christian/git/aoc/2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/git/aoc/2019/build

# Include any dependencies generated for this target.
include CMakeFiles/day10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/day10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/day10.dir/flags.make

CMakeFiles/day10.dir/day10/main.cpp.o: CMakeFiles/day10.dir/flags.make
CMakeFiles/day10.dir/day10/main.cpp.o: ../day10/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/git/aoc/2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/day10.dir/day10/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/day10.dir/day10/main.cpp.o -c /home/christian/git/aoc/2019/day10/main.cpp

CMakeFiles/day10.dir/day10/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day10.dir/day10/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/git/aoc/2019/day10/main.cpp > CMakeFiles/day10.dir/day10/main.cpp.i

CMakeFiles/day10.dir/day10/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day10.dir/day10/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/git/aoc/2019/day10/main.cpp -o CMakeFiles/day10.dir/day10/main.cpp.s

# Object files for target day10
day10_OBJECTS = \
"CMakeFiles/day10.dir/day10/main.cpp.o"

# External object files for target day10
day10_EXTERNAL_OBJECTS =

day10: CMakeFiles/day10.dir/day10/main.cpp.o
day10: CMakeFiles/day10.dir/build.make
day10: CMakeFiles/day10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/git/aoc/2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable day10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/day10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/day10.dir/build: day10

.PHONY : CMakeFiles/day10.dir/build

CMakeFiles/day10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/day10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/day10.dir/clean

CMakeFiles/day10.dir/depend:
	cd /home/christian/git/aoc/2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/git/aoc/2019 /home/christian/git/aoc/2019 /home/christian/git/aoc/2019/build /home/christian/git/aoc/2019/build /home/christian/git/aoc/2019/build/CMakeFiles/day10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/day10.dir/depend

