# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/xqhuang/linux_learn/sample03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/xqhuang/linux_learn/sample03/build

# Include any dependencies generated for this target.
include world/CMakeFiles/worldlib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include world/CMakeFiles/worldlib.dir/compiler_depend.make

# Include the progress variables for this target.
include world/CMakeFiles/worldlib.dir/progress.make

# Include the compile flags for this target's objects.
include world/CMakeFiles/worldlib.dir/flags.make

world/CMakeFiles/worldlib.dir/world.c.o: world/CMakeFiles/worldlib.dir/flags.make
world/CMakeFiles/worldlib.dir/world.c.o: ../world/world.c
world/CMakeFiles/worldlib.dir/world.c.o: world/CMakeFiles/worldlib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/xqhuang/linux_learn/sample03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object world/CMakeFiles/worldlib.dir/world.c.o"
	cd /root/xqhuang/linux_learn/sample03/build/world && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT world/CMakeFiles/worldlib.dir/world.c.o -MF CMakeFiles/worldlib.dir/world.c.o.d -o CMakeFiles/worldlib.dir/world.c.o -c /root/xqhuang/linux_learn/sample03/world/world.c

world/CMakeFiles/worldlib.dir/world.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/worldlib.dir/world.c.i"
	cd /root/xqhuang/linux_learn/sample03/build/world && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/xqhuang/linux_learn/sample03/world/world.c > CMakeFiles/worldlib.dir/world.c.i

world/CMakeFiles/worldlib.dir/world.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/worldlib.dir/world.c.s"
	cd /root/xqhuang/linux_learn/sample03/build/world && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/xqhuang/linux_learn/sample03/world/world.c -o CMakeFiles/worldlib.dir/world.c.s

# Object files for target worldlib
worldlib_OBJECTS = \
"CMakeFiles/worldlib.dir/world.c.o"

# External object files for target worldlib
worldlib_EXTERNAL_OBJECTS =

world/libworldlib.so: world/CMakeFiles/worldlib.dir/world.c.o
world/libworldlib.so: world/CMakeFiles/worldlib.dir/build.make
world/libworldlib.so: world/CMakeFiles/worldlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/xqhuang/linux_learn/sample03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libworldlib.so"
	cd /root/xqhuang/linux_learn/sample03/build/world && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/worldlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
world/CMakeFiles/worldlib.dir/build: world/libworldlib.so
.PHONY : world/CMakeFiles/worldlib.dir/build

world/CMakeFiles/worldlib.dir/clean:
	cd /root/xqhuang/linux_learn/sample03/build/world && $(CMAKE_COMMAND) -P CMakeFiles/worldlib.dir/cmake_clean.cmake
.PHONY : world/CMakeFiles/worldlib.dir/clean

world/CMakeFiles/worldlib.dir/depend:
	cd /root/xqhuang/linux_learn/sample03/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/xqhuang/linux_learn/sample03 /root/xqhuang/linux_learn/sample03/world /root/xqhuang/linux_learn/sample03/build /root/xqhuang/linux_learn/sample03/build/world /root/xqhuang/linux_learn/sample03/build/world/CMakeFiles/worldlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : world/CMakeFiles/worldlib.dir/depend

