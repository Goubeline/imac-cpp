# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = C:\WinLibs\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\WinLibs\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\IMAC\C++\td3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\IMAC\C++\td3\build

# Include any dependencies generated for this target.
include CMakeFiles/exo2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exo2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exo2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exo2.dir/flags.make

CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.obj: CMakeFiles/exo2.dir/flags.make
CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.obj: C:/IMAC/C++/td3/exo2/td03_ex02.cpp
CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.obj: CMakeFiles/exo2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\IMAC\C++\td3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.obj"
	C:\WinLibs\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.obj -MF CMakeFiles\exo2.dir\exo2\td03_ex02.cpp.obj.d -o CMakeFiles\exo2.dir\exo2\td03_ex02.cpp.obj -c C:\IMAC\C++\td3\exo2\td03_ex02.cpp

CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.i"
	C:\WinLibs\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\IMAC\C++\td3\exo2\td03_ex02.cpp > CMakeFiles\exo2.dir\exo2\td03_ex02.cpp.i

CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.s"
	C:\WinLibs\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\IMAC\C++\td3\exo2\td03_ex02.cpp -o CMakeFiles\exo2.dir\exo2\td03_ex02.cpp.s

# Object files for target exo2
exo2_OBJECTS = \
"CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.obj"

# External object files for target exo2
exo2_EXTERNAL_OBJECTS =

C:/IMAC/C++/td3/bin/Debug/exo2.exe: CMakeFiles/exo2.dir/exo2/td03_ex02.cpp.obj
C:/IMAC/C++/td3/bin/Debug/exo2.exe: CMakeFiles/exo2.dir/build.make
C:/IMAC/C++/td3/bin/Debug/exo2.exe: CMakeFiles/exo2.dir/linkLibs.rsp
C:/IMAC/C++/td3/bin/Debug/exo2.exe: CMakeFiles/exo2.dir/objects1.rsp
C:/IMAC/C++/td3/bin/Debug/exo2.exe: CMakeFiles/exo2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\IMAC\C++\td3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C:\IMAC\C++\td3\bin\Debug\exo2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\exo2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exo2.dir/build: C:/IMAC/C++/td3/bin/Debug/exo2.exe
.PHONY : CMakeFiles/exo2.dir/build

CMakeFiles/exo2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\exo2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/exo2.dir/clean

CMakeFiles/exo2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\IMAC\C++\td3 C:\IMAC\C++\td3 C:\IMAC\C++\td3\build C:\IMAC\C++\td3\build C:\IMAC\C++\td3\build\CMakeFiles\exo2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/exo2.dir/depend

