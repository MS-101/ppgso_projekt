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
include CMakeFiles/ppgso.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ppgso.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ppgso.dir/flags.make

CMakeFiles/ppgso.dir/ppgso/mesh.cpp.obj: CMakeFiles/ppgso.dir/flags.make
CMakeFiles/ppgso.dir/ppgso/mesh.cpp.obj: CMakeFiles/ppgso.dir/includes_CXX.rsp
CMakeFiles/ppgso.dir/ppgso/mesh.cpp.obj: ../ppgso/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ppgso.dir/ppgso/mesh.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ppgso.dir\ppgso\mesh.cpp.obj -c H:\Reposits\ppgso_projekt\ppgso\mesh.cpp

CMakeFiles/ppgso.dir/ppgso/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppgso.dir/ppgso/mesh.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\ppgso\mesh.cpp > CMakeFiles\ppgso.dir\ppgso\mesh.cpp.i

CMakeFiles/ppgso.dir/ppgso/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppgso.dir/ppgso/mesh.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\ppgso\mesh.cpp -o CMakeFiles\ppgso.dir\ppgso\mesh.cpp.s

CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.obj: CMakeFiles/ppgso.dir/flags.make
CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.obj: CMakeFiles/ppgso.dir/includes_CXX.rsp
CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.obj: ../ppgso/tiny_obj_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ppgso.dir\ppgso\tiny_obj_loader.cpp.obj -c H:\Reposits\ppgso_projekt\ppgso\tiny_obj_loader.cpp

CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\ppgso\tiny_obj_loader.cpp > CMakeFiles\ppgso.dir\ppgso\tiny_obj_loader.cpp.i

CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\ppgso\tiny_obj_loader.cpp -o CMakeFiles\ppgso.dir\ppgso\tiny_obj_loader.cpp.s

CMakeFiles/ppgso.dir/ppgso/shader.cpp.obj: CMakeFiles/ppgso.dir/flags.make
CMakeFiles/ppgso.dir/ppgso/shader.cpp.obj: CMakeFiles/ppgso.dir/includes_CXX.rsp
CMakeFiles/ppgso.dir/ppgso/shader.cpp.obj: ../ppgso/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ppgso.dir/ppgso/shader.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ppgso.dir\ppgso\shader.cpp.obj -c H:\Reposits\ppgso_projekt\ppgso\shader.cpp

CMakeFiles/ppgso.dir/ppgso/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppgso.dir/ppgso/shader.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\ppgso\shader.cpp > CMakeFiles\ppgso.dir\ppgso\shader.cpp.i

CMakeFiles/ppgso.dir/ppgso/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppgso.dir/ppgso/shader.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\ppgso\shader.cpp -o CMakeFiles\ppgso.dir\ppgso\shader.cpp.s

CMakeFiles/ppgso.dir/ppgso/image.cpp.obj: CMakeFiles/ppgso.dir/flags.make
CMakeFiles/ppgso.dir/ppgso/image.cpp.obj: CMakeFiles/ppgso.dir/includes_CXX.rsp
CMakeFiles/ppgso.dir/ppgso/image.cpp.obj: ../ppgso/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ppgso.dir/ppgso/image.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ppgso.dir\ppgso\image.cpp.obj -c H:\Reposits\ppgso_projekt\ppgso\image.cpp

CMakeFiles/ppgso.dir/ppgso/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppgso.dir/ppgso/image.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\ppgso\image.cpp > CMakeFiles\ppgso.dir\ppgso\image.cpp.i

CMakeFiles/ppgso.dir/ppgso/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppgso.dir/ppgso/image.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\ppgso\image.cpp -o CMakeFiles\ppgso.dir\ppgso\image.cpp.s

CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.obj: CMakeFiles/ppgso.dir/flags.make
CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.obj: CMakeFiles/ppgso.dir/includes_CXX.rsp
CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.obj: ../ppgso/image_bmp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ppgso.dir\ppgso\image_bmp.cpp.obj -c H:\Reposits\ppgso_projekt\ppgso\image_bmp.cpp

CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\ppgso\image_bmp.cpp > CMakeFiles\ppgso.dir\ppgso\image_bmp.cpp.i

CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\ppgso\image_bmp.cpp -o CMakeFiles\ppgso.dir\ppgso\image_bmp.cpp.s

CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.obj: CMakeFiles/ppgso.dir/flags.make
CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.obj: CMakeFiles/ppgso.dir/includes_CXX.rsp
CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.obj: ../ppgso/image_raw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ppgso.dir\ppgso\image_raw.cpp.obj -c H:\Reposits\ppgso_projekt\ppgso\image_raw.cpp

CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\ppgso\image_raw.cpp > CMakeFiles\ppgso.dir\ppgso\image_raw.cpp.i

CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\ppgso\image_raw.cpp -o CMakeFiles\ppgso.dir\ppgso\image_raw.cpp.s

CMakeFiles/ppgso.dir/ppgso/texture.cpp.obj: CMakeFiles/ppgso.dir/flags.make
CMakeFiles/ppgso.dir/ppgso/texture.cpp.obj: CMakeFiles/ppgso.dir/includes_CXX.rsp
CMakeFiles/ppgso.dir/ppgso/texture.cpp.obj: ../ppgso/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ppgso.dir/ppgso/texture.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ppgso.dir\ppgso\texture.cpp.obj -c H:\Reposits\ppgso_projekt\ppgso\texture.cpp

CMakeFiles/ppgso.dir/ppgso/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppgso.dir/ppgso/texture.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\ppgso\texture.cpp > CMakeFiles\ppgso.dir\ppgso\texture.cpp.i

CMakeFiles/ppgso.dir/ppgso/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppgso.dir/ppgso/texture.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\ppgso\texture.cpp -o CMakeFiles\ppgso.dir\ppgso\texture.cpp.s

CMakeFiles/ppgso.dir/ppgso/window.cpp.obj: CMakeFiles/ppgso.dir/flags.make
CMakeFiles/ppgso.dir/ppgso/window.cpp.obj: CMakeFiles/ppgso.dir/includes_CXX.rsp
CMakeFiles/ppgso.dir/ppgso/window.cpp.obj: ../ppgso/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ppgso.dir/ppgso/window.cpp.obj"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ppgso.dir\ppgso\window.cpp.obj -c H:\Reposits\ppgso_projekt\ppgso\window.cpp

CMakeFiles/ppgso.dir/ppgso/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppgso.dir/ppgso/window.cpp.i"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\Reposits\ppgso_projekt\ppgso\window.cpp > CMakeFiles\ppgso.dir\ppgso\window.cpp.i

CMakeFiles/ppgso.dir/ppgso/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppgso.dir/ppgso/window.cpp.s"
	H:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\Reposits\ppgso_projekt\ppgso\window.cpp -o CMakeFiles\ppgso.dir\ppgso\window.cpp.s

# Object files for target ppgso
ppgso_OBJECTS = \
"CMakeFiles/ppgso.dir/ppgso/mesh.cpp.obj" \
"CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.obj" \
"CMakeFiles/ppgso.dir/ppgso/shader.cpp.obj" \
"CMakeFiles/ppgso.dir/ppgso/image.cpp.obj" \
"CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.obj" \
"CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.obj" \
"CMakeFiles/ppgso.dir/ppgso/texture.cpp.obj" \
"CMakeFiles/ppgso.dir/ppgso/window.cpp.obj"

# External object files for target ppgso
ppgso_EXTERNAL_OBJECTS =

libppgso.a: CMakeFiles/ppgso.dir/ppgso/mesh.cpp.obj
libppgso.a: CMakeFiles/ppgso.dir/ppgso/tiny_obj_loader.cpp.obj
libppgso.a: CMakeFiles/ppgso.dir/ppgso/shader.cpp.obj
libppgso.a: CMakeFiles/ppgso.dir/ppgso/image.cpp.obj
libppgso.a: CMakeFiles/ppgso.dir/ppgso/image_bmp.cpp.obj
libppgso.a: CMakeFiles/ppgso.dir/ppgso/image_raw.cpp.obj
libppgso.a: CMakeFiles/ppgso.dir/ppgso/texture.cpp.obj
libppgso.a: CMakeFiles/ppgso.dir/ppgso/window.cpp.obj
libppgso.a: CMakeFiles/ppgso.dir/build.make
libppgso.a: CMakeFiles/ppgso.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libppgso.a"
	$(CMAKE_COMMAND) -P CMakeFiles\ppgso.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ppgso.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ppgso.dir/build: libppgso.a
.PHONY : CMakeFiles/ppgso.dir/build

CMakeFiles/ppgso.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ppgso.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ppgso.dir/clean

CMakeFiles/ppgso.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\Reposits\ppgso_projekt H:\Reposits\ppgso_projekt H:\Reposits\ppgso_projekt\cmake-build-debug H:\Reposits\ppgso_projekt\cmake-build-debug H:\Reposits\ppgso_projekt\cmake-build-debug\CMakeFiles\ppgso.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ppgso.dir/depend

