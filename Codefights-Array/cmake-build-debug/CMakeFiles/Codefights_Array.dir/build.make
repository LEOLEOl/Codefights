# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\it_cs\JetBrains\C++\Codefights-Array

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\it_cs\JetBrains\C++\Codefights-Array\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Codefights_Array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Codefights_Array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Codefights_Array.dir/flags.make

CMakeFiles/Codefights_Array.dir/main.cpp.obj: CMakeFiles/Codefights_Array.dir/flags.make
CMakeFiles/Codefights_Array.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\it_cs\JetBrains\C++\Codefights-Array\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Codefights_Array.dir/main.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Codefights_Array.dir\main.cpp.obj -c E:\it_cs\JetBrains\C++\Codefights-Array\main.cpp

CMakeFiles/Codefights_Array.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Codefights_Array.dir/main.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\it_cs\JetBrains\C++\Codefights-Array\main.cpp > CMakeFiles\Codefights_Array.dir\main.cpp.i

CMakeFiles/Codefights_Array.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Codefights_Array.dir/main.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\it_cs\JetBrains\C++\Codefights-Array\main.cpp -o CMakeFiles\Codefights_Array.dir\main.cpp.s

CMakeFiles/Codefights_Array.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Codefights_Array.dir/main.cpp.obj.requires

CMakeFiles/Codefights_Array.dir/main.cpp.obj.provides: CMakeFiles/Codefights_Array.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Codefights_Array.dir\build.make CMakeFiles/Codefights_Array.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Codefights_Array.dir/main.cpp.obj.provides

CMakeFiles/Codefights_Array.dir/main.cpp.obj.provides.build: CMakeFiles/Codefights_Array.dir/main.cpp.obj


# Object files for target Codefights_Array
Codefights_Array_OBJECTS = \
"CMakeFiles/Codefights_Array.dir/main.cpp.obj"

# External object files for target Codefights_Array
Codefights_Array_EXTERNAL_OBJECTS =

Codefights_Array.exe: CMakeFiles/Codefights_Array.dir/main.cpp.obj
Codefights_Array.exe: CMakeFiles/Codefights_Array.dir/build.make
Codefights_Array.exe: CMakeFiles/Codefights_Array.dir/linklibs.rsp
Codefights_Array.exe: CMakeFiles/Codefights_Array.dir/objects1.rsp
Codefights_Array.exe: CMakeFiles/Codefights_Array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\it_cs\JetBrains\C++\Codefights-Array\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Codefights_Array.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Codefights_Array.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Codefights_Array.dir/build: Codefights_Array.exe

.PHONY : CMakeFiles/Codefights_Array.dir/build

CMakeFiles/Codefights_Array.dir/requires: CMakeFiles/Codefights_Array.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Codefights_Array.dir/requires

CMakeFiles/Codefights_Array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Codefights_Array.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Codefights_Array.dir/clean

CMakeFiles/Codefights_Array.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\it_cs\JetBrains\C++\Codefights-Array E:\it_cs\JetBrains\C++\Codefights-Array E:\it_cs\JetBrains\C++\Codefights-Array\cmake-build-debug E:\it_cs\JetBrains\C++\Codefights-Array\cmake-build-debug E:\it_cs\JetBrains\C++\Codefights-Array\cmake-build-debug\CMakeFiles\Codefights_Array.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Codefights_Array.dir/depend

