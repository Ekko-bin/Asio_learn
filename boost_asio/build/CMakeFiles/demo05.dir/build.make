# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/jb/code/Asio_Prcatice/boost_asio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jb/code/Asio_Prcatice/boost_asio/build

# Include any dependencies generated for this target.
include CMakeFiles/demo05.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo05.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo05.dir/flags.make

CMakeFiles/demo05.dir/src/demo05.cpp.o: CMakeFiles/demo05.dir/flags.make
CMakeFiles/demo05.dir/src/demo05.cpp.o: ../src/demo05.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jb/code/Asio_Prcatice/boost_asio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo05.dir/src/demo05.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo05.dir/src/demo05.cpp.o -c /home/jb/code/Asio_Prcatice/boost_asio/src/demo05.cpp

CMakeFiles/demo05.dir/src/demo05.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo05.dir/src/demo05.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jb/code/Asio_Prcatice/boost_asio/src/demo05.cpp > CMakeFiles/demo05.dir/src/demo05.cpp.i

CMakeFiles/demo05.dir/src/demo05.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo05.dir/src/demo05.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jb/code/Asio_Prcatice/boost_asio/src/demo05.cpp -o CMakeFiles/demo05.dir/src/demo05.cpp.s

CMakeFiles/demo05.dir/src/demo05.cpp.o.requires:

.PHONY : CMakeFiles/demo05.dir/src/demo05.cpp.o.requires

CMakeFiles/demo05.dir/src/demo05.cpp.o.provides: CMakeFiles/demo05.dir/src/demo05.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo05.dir/build.make CMakeFiles/demo05.dir/src/demo05.cpp.o.provides.build
.PHONY : CMakeFiles/demo05.dir/src/demo05.cpp.o.provides

CMakeFiles/demo05.dir/src/demo05.cpp.o.provides.build: CMakeFiles/demo05.dir/src/demo05.cpp.o


# Object files for target demo05
demo05_OBJECTS = \
"CMakeFiles/demo05.dir/src/demo05.cpp.o"

# External object files for target demo05
demo05_EXTERNAL_OBJECTS =

demo05: CMakeFiles/demo05.dir/src/demo05.cpp.o
demo05: CMakeFiles/demo05.dir/build.make
demo05: CMakeFiles/demo05.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jb/code/Asio_Prcatice/boost_asio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable demo05"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo05.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo05.dir/build: demo05

.PHONY : CMakeFiles/demo05.dir/build

CMakeFiles/demo05.dir/requires: CMakeFiles/demo05.dir/src/demo05.cpp.o.requires

.PHONY : CMakeFiles/demo05.dir/requires

CMakeFiles/demo05.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo05.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo05.dir/clean

CMakeFiles/demo05.dir/depend:
	cd /home/jb/code/Asio_Prcatice/boost_asio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jb/code/Asio_Prcatice/boost_asio /home/jb/code/Asio_Prcatice/boost_asio /home/jb/code/Asio_Prcatice/boost_asio/build /home/jb/code/Asio_Prcatice/boost_asio/build /home/jb/code/Asio_Prcatice/boost_asio/build/CMakeFiles/demo05.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo05.dir/depend
