# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "H:\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "H:\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\Reposits\ppgso_projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\Reposits\ppgso_projekt\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gl6_mesh.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/gl6_mesh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gl6_mesh.dir/flags.make

CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.obj: CMakeFiles/gl6_mesh.dir/flags.make
CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.obj: CMakeFiles/gl6_mesh.dir/includes_CXX.rsp
CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.obj: ../src/gl6_mesh/gl6_mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gl6_mesh.dir\src\gl6_mesh\gl6_mesh.cpp.obj -c H:\Reposits\ppgso_projekt\src\gl6_mesh\gl6_mesh.cpp

CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\src\gl6_mesh\gl6_mesh.cpp > CMakeFiles\gl6_mesh.dir\src\gl6_mesh\gl6_mesh.cpp.i

CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\src\gl6_mesh\gl6_mesh.cpp -o CMakeFiles\gl6_mesh.dir\src\gl6_mesh\gl6_mesh.cpp.s

# Object files for target gl6_mesh
gl6_mesh_OBJECTS = \
"CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.obj"

# External object files for target gl6_mesh
gl6_mesh_EXTERNAL_OBJECTS =

gl6_mesh.exe: CMakeFiles/gl6_mesh.dir/src/gl6_mesh/gl6_mesh.cpp.obj
gl6_mesh.exe: CMakeFiles/gl6_mesh.dir/build.make
gl6_mesh.exe: libppgso.a
gl6_mesh.exe: libshaders.a
gl6_mesh.exe: ../dependencies/lib/mingw/libglfw3.a
gl6_mesh.exe: ../dependencies/lib/mingw/libglew32.a
gl6_mesh.exe: CMakeFiles/gl6_mesh.dir/linklibs.rsp
gl6_mesh.exe: CMakeFiles/gl6_mesh.dir/objects1.rsp
gl6_mesh.exe: CMakeFiles/gl6_mesh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gl6_mesh.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gl6_mesh.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gl6_mesh.dir/build: gl6_mesh.exe
.PHONY : CMakeFiles/gl6_mesh.dir/build

CMakeFiles/gl6_mesh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\gl6_mesh.dir\cmake_clean.cmake
.PHONY : CMakeFiles/gl6_mesh.dir/clean

CMakeFiles/gl6_mesh.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\Reposits\ppgso_projekt H:\Reposits\ppgso_projekt H:\Reposits\ppgso_projekt\cmake-build-debug H:\Reposits\ppgso_projekt\cmake-build-debug H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles\gl6_mesh.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gl6_mesh.dir/depend

