# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/touch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/touch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/touch.dir/flags.make

CMakeFiles/touch.dir/lab05/touch.c.o: CMakeFiles/touch.dir/flags.make
CMakeFiles/touch.dir/lab05/touch.c.o: ../lab05/touch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/touch.dir/lab05/touch.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/touch.dir/lab05/touch.c.o   -c "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/lab05/touch.c"

CMakeFiles/touch.dir/lab05/touch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/touch.dir/lab05/touch.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/lab05/touch.c" > CMakeFiles/touch.dir/lab05/touch.c.i

CMakeFiles/touch.dir/lab05/touch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/touch.dir/lab05/touch.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/lab05/touch.c" -o CMakeFiles/touch.dir/lab05/touch.c.s

# Object files for target touch
touch_OBJECTS = \
"CMakeFiles/touch.dir/lab05/touch.c.o"

# External object files for target touch
touch_EXTERNAL_OBJECTS =

touch: CMakeFiles/touch.dir/lab05/touch.c.o
touch: CMakeFiles/touch.dir/build.make
touch: CMakeFiles/touch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable touch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/touch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/touch.dir/build: touch

.PHONY : CMakeFiles/touch.dir/build

CMakeFiles/touch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/touch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/touch.dir/clean

CMakeFiles/touch.dir/depend:
	cd "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code" "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code" "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/cmake-build-debug" "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/cmake-build-debug" "/Volumes/GoogleDrive/My Drive/Unimore/Didattica/operatingsystemsbsc/c/code/cmake-build-debug/CMakeFiles/touch.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/touch.dir/depend

