# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/pawel/Pobrane/clion-2017.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/pawel/Pobrane/clion-2017.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pawel/CLionProjects/SPD_lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pawel/CLionProjects/SPD_lab1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SPD_lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SPD_lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SPD_lab1.dir/flags.make

CMakeFiles/SPD_lab1.dir/main.cpp.o: CMakeFiles/SPD_lab1.dir/flags.make
CMakeFiles/SPD_lab1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pawel/CLionProjects/SPD_lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SPD_lab1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD_lab1.dir/main.cpp.o -c /home/pawel/CLionProjects/SPD_lab1/main.cpp

CMakeFiles/SPD_lab1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD_lab1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pawel/CLionProjects/SPD_lab1/main.cpp > CMakeFiles/SPD_lab1.dir/main.cpp.i

CMakeFiles/SPD_lab1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD_lab1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pawel/CLionProjects/SPD_lab1/main.cpp -o CMakeFiles/SPD_lab1.dir/main.cpp.s

CMakeFiles/SPD_lab1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SPD_lab1.dir/main.cpp.o.requires

CMakeFiles/SPD_lab1.dir/main.cpp.o.provides: CMakeFiles/SPD_lab1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SPD_lab1.dir/build.make CMakeFiles/SPD_lab1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SPD_lab1.dir/main.cpp.o.provides

CMakeFiles/SPD_lab1.dir/main.cpp.o.provides.build: CMakeFiles/SPD_lab1.dir/main.cpp.o


# Object files for target SPD_lab1
SPD_lab1_OBJECTS = \
"CMakeFiles/SPD_lab1.dir/main.cpp.o"

# External object files for target SPD_lab1
SPD_lab1_EXTERNAL_OBJECTS =

SPD_lab1: CMakeFiles/SPD_lab1.dir/main.cpp.o
SPD_lab1: CMakeFiles/SPD_lab1.dir/build.make
SPD_lab1: CMakeFiles/SPD_lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pawel/CLionProjects/SPD_lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SPD_lab1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SPD_lab1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SPD_lab1.dir/build: SPD_lab1

.PHONY : CMakeFiles/SPD_lab1.dir/build

CMakeFiles/SPD_lab1.dir/requires: CMakeFiles/SPD_lab1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/SPD_lab1.dir/requires

CMakeFiles/SPD_lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SPD_lab1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SPD_lab1.dir/clean

CMakeFiles/SPD_lab1.dir/depend:
	cd /home/pawel/CLionProjects/SPD_lab1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pawel/CLionProjects/SPD_lab1 /home/pawel/CLionProjects/SPD_lab1 /home/pawel/CLionProjects/SPD_lab1/cmake-build-debug /home/pawel/CLionProjects/SPD_lab1/cmake-build-debug /home/pawel/CLionProjects/SPD_lab1/cmake-build-debug/CMakeFiles/SPD_lab1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SPD_lab1.dir/depend

