# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/hurafhev/Dokumente/particle_tracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hurafhev/Dokumente/particle_tracker

# Include any dependencies generated for this target.
include CMakeFiles/mark.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mark.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mark.exe.dir/flags.make

CMakeFiles/mark.exe.dir/main.cpp.o: CMakeFiles/mark.exe.dir/flags.make
CMakeFiles/mark.exe.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hurafhev/Dokumente/particle_tracker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mark.exe.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mark.exe.dir/main.cpp.o -c /home/hurafhev/Dokumente/particle_tracker/main.cpp

CMakeFiles/mark.exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mark.exe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hurafhev/Dokumente/particle_tracker/main.cpp > CMakeFiles/mark.exe.dir/main.cpp.i

CMakeFiles/mark.exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mark.exe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hurafhev/Dokumente/particle_tracker/main.cpp -o CMakeFiles/mark.exe.dir/main.cpp.s

# Object files for target mark.exe
mark_exe_OBJECTS = \
"CMakeFiles/mark.exe.dir/main.cpp.o"

# External object files for target mark.exe
mark_exe_EXTERNAL_OBJECTS =

mark.exe: CMakeFiles/mark.exe.dir/main.cpp.o
mark.exe: CMakeFiles/mark.exe.dir/build.make
mark.exe: lib/liblib.a
mark.exe: CMakeFiles/mark.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hurafhev/Dokumente/particle_tracker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mark.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mark.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mark.exe.dir/build: mark.exe

.PHONY : CMakeFiles/mark.exe.dir/build

CMakeFiles/mark.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mark.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mark.exe.dir/clean

CMakeFiles/mark.exe.dir/depend:
	cd /home/hurafhev/Dokumente/particle_tracker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hurafhev/Dokumente/particle_tracker /home/hurafhev/Dokumente/particle_tracker /home/hurafhev/Dokumente/particle_tracker /home/hurafhev/Dokumente/particle_tracker /home/hurafhev/Dokumente/particle_tracker/CMakeFiles/mark.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mark.exe.dir/depend

