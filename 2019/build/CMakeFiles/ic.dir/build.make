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
include CMakeFiles/ic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ic.dir/flags.make

CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.o: CMakeFiles/ic.dir/flags.make
CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.o: ../intcode_computer/intcode_computer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/git/aoc/2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.o -c /home/christian/git/aoc/2019/intcode_computer/intcode_computer.cpp

CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/git/aoc/2019/intcode_computer/intcode_computer.cpp > CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.i

CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/git/aoc/2019/intcode_computer/intcode_computer.cpp -o CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.s

# Object files for target ic
ic_OBJECTS = \
"CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.o"

# External object files for target ic
ic_EXTERNAL_OBJECTS =

libic.so: CMakeFiles/ic.dir/intcode_computer/intcode_computer.cpp.o
libic.so: CMakeFiles/ic.dir/build.make
libic.so: CMakeFiles/ic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/git/aoc/2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libic.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ic.dir/build: libic.so

.PHONY : CMakeFiles/ic.dir/build

CMakeFiles/ic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ic.dir/clean

CMakeFiles/ic.dir/depend:
	cd /home/christian/git/aoc/2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/git/aoc/2019 /home/christian/git/aoc/2019 /home/christian/git/aoc/2019/build /home/christian/git/aoc/2019/build /home/christian/git/aoc/2019/build/CMakeFiles/ic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ic.dir/depend

