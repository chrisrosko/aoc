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
include CMakeFiles/day2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/day2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/day2.dir/flags.make

CMakeFiles/day2.dir/day2/main.cpp.o: CMakeFiles/day2.dir/flags.make
CMakeFiles/day2.dir/day2/main.cpp.o: ../day2/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/git/aoc/2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/day2.dir/day2/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/day2.dir/day2/main.cpp.o -c /home/christian/git/aoc/2019/day2/main.cpp

CMakeFiles/day2.dir/day2/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day2.dir/day2/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/git/aoc/2019/day2/main.cpp > CMakeFiles/day2.dir/day2/main.cpp.i

CMakeFiles/day2.dir/day2/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day2.dir/day2/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/git/aoc/2019/day2/main.cpp -o CMakeFiles/day2.dir/day2/main.cpp.s

# Object files for target day2
day2_OBJECTS = \
"CMakeFiles/day2.dir/day2/main.cpp.o"

# External object files for target day2
day2_EXTERNAL_OBJECTS =

day2: CMakeFiles/day2.dir/day2/main.cpp.o
day2: CMakeFiles/day2.dir/build.make
day2: libic.so
day2: CMakeFiles/day2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/git/aoc/2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable day2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/day2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/day2.dir/build: day2

.PHONY : CMakeFiles/day2.dir/build

CMakeFiles/day2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/day2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/day2.dir/clean

CMakeFiles/day2.dir/depend:
	cd /home/christian/git/aoc/2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/git/aoc/2019 /home/christian/git/aoc/2019 /home/christian/git/aoc/2019/build /home/christian/git/aoc/2019/build /home/christian/git/aoc/2019/build/CMakeFiles/day2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/day2.dir/depend

