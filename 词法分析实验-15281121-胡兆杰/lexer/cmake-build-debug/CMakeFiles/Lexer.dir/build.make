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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lexer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lexer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lexer.dir/flags.make

CMakeFiles/Lexer.dir/main.cpp.o: CMakeFiles/Lexer.dir/flags.make
CMakeFiles/Lexer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lexer.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lexer.dir/main.cpp.o -c /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/main.cpp

CMakeFiles/Lexer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lexer.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/main.cpp > CMakeFiles/Lexer.dir/main.cpp.i

CMakeFiles/Lexer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lexer.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/main.cpp -o CMakeFiles/Lexer.dir/main.cpp.s

CMakeFiles/Lexer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Lexer.dir/main.cpp.o.requires

CMakeFiles/Lexer.dir/main.cpp.o.provides: CMakeFiles/Lexer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lexer.dir/build.make CMakeFiles/Lexer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Lexer.dir/main.cpp.o.provides

CMakeFiles/Lexer.dir/main.cpp.o.provides.build: CMakeFiles/Lexer.dir/main.cpp.o


CMakeFiles/Lexer.dir/lexer.cpp.o: CMakeFiles/Lexer.dir/flags.make
CMakeFiles/Lexer.dir/lexer.cpp.o: ../lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lexer.dir/lexer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lexer.dir/lexer.cpp.o -c /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/lexer.cpp

CMakeFiles/Lexer.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lexer.dir/lexer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/lexer.cpp > CMakeFiles/Lexer.dir/lexer.cpp.i

CMakeFiles/Lexer.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lexer.dir/lexer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/lexer.cpp -o CMakeFiles/Lexer.dir/lexer.cpp.s

CMakeFiles/Lexer.dir/lexer.cpp.o.requires:

.PHONY : CMakeFiles/Lexer.dir/lexer.cpp.o.requires

CMakeFiles/Lexer.dir/lexer.cpp.o.provides: CMakeFiles/Lexer.dir/lexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lexer.dir/build.make CMakeFiles/Lexer.dir/lexer.cpp.o.provides.build
.PHONY : CMakeFiles/Lexer.dir/lexer.cpp.o.provides

CMakeFiles/Lexer.dir/lexer.cpp.o.provides.build: CMakeFiles/Lexer.dir/lexer.cpp.o


# Object files for target Lexer
Lexer_OBJECTS = \
"CMakeFiles/Lexer.dir/main.cpp.o" \
"CMakeFiles/Lexer.dir/lexer.cpp.o"

# External object files for target Lexer
Lexer_EXTERNAL_OBJECTS =

Lexer: CMakeFiles/Lexer.dir/main.cpp.o
Lexer: CMakeFiles/Lexer.dir/lexer.cpp.o
Lexer: CMakeFiles/Lexer.dir/build.make
Lexer: CMakeFiles/Lexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lexer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lexer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lexer.dir/build: Lexer

.PHONY : CMakeFiles/Lexer.dir/build

CMakeFiles/Lexer.dir/requires: CMakeFiles/Lexer.dir/main.cpp.o.requires
CMakeFiles/Lexer.dir/requires: CMakeFiles/Lexer.dir/lexer.cpp.o.requires

.PHONY : CMakeFiles/Lexer.dir/requires

CMakeFiles/Lexer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lexer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lexer.dir/clean

CMakeFiles/Lexer.dir/depend:
	cd /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件 /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件 /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/cmake-build-debug /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/cmake-build-debug /Users/hhzjj/Documents/bjtu/大三/编译原理/lab/词法分析实验-15281121-胡兆杰/源程序及测试文件/cmake-build-debug/CMakeFiles/Lexer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lexer.dir/depend

