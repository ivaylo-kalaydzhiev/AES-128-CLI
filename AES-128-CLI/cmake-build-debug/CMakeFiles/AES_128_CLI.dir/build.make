# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AES_128_CLI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AES_128_CLI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AES_128_CLI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AES_128_CLI.dir/flags.make

CMakeFiles/AES_128_CLI.dir/main.cpp.o: CMakeFiles/AES_128_CLI.dir/flags.make
CMakeFiles/AES_128_CLI.dir/main.cpp.o: /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/main.cpp
CMakeFiles/AES_128_CLI.dir/main.cpp.o: CMakeFiles/AES_128_CLI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AES_128_CLI.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES_128_CLI.dir/main.cpp.o -MF CMakeFiles/AES_128_CLI.dir/main.cpp.o.d -o CMakeFiles/AES_128_CLI.dir/main.cpp.o -c /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/main.cpp

CMakeFiles/AES_128_CLI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AES_128_CLI.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/main.cpp > CMakeFiles/AES_128_CLI.dir/main.cpp.i

CMakeFiles/AES_128_CLI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AES_128_CLI.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/main.cpp -o CMakeFiles/AES_128_CLI.dir/main.cpp.s

CMakeFiles/AES_128_CLI.dir/Program.cpp.o: CMakeFiles/AES_128_CLI.dir/flags.make
CMakeFiles/AES_128_CLI.dir/Program.cpp.o: /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/Program.cpp
CMakeFiles/AES_128_CLI.dir/Program.cpp.o: CMakeFiles/AES_128_CLI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AES_128_CLI.dir/Program.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES_128_CLI.dir/Program.cpp.o -MF CMakeFiles/AES_128_CLI.dir/Program.cpp.o.d -o CMakeFiles/AES_128_CLI.dir/Program.cpp.o -c /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/Program.cpp

CMakeFiles/AES_128_CLI.dir/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AES_128_CLI.dir/Program.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/Program.cpp > CMakeFiles/AES_128_CLI.dir/Program.cpp.i

CMakeFiles/AES_128_CLI.dir/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AES_128_CLI.dir/Program.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/Program.cpp -o CMakeFiles/AES_128_CLI.dir/Program.cpp.s

CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o: CMakeFiles/AES_128_CLI.dir/flags.make
CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o: /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/FileManager.cpp
CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o: CMakeFiles/AES_128_CLI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o -MF CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o.d -o CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o -c /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/FileManager.cpp

CMakeFiles/AES_128_CLI.dir/FileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AES_128_CLI.dir/FileManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/FileManager.cpp > CMakeFiles/AES_128_CLI.dir/FileManager.cpp.i

CMakeFiles/AES_128_CLI.dir/FileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AES_128_CLI.dir/FileManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/FileManager.cpp -o CMakeFiles/AES_128_CLI.dir/FileManager.cpp.s

CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o: CMakeFiles/AES_128_CLI.dir/flags.make
CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o: /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/AESCryptographer.cpp
CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o: CMakeFiles/AES_128_CLI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o -MF CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o.d -o CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o -c /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/AESCryptographer.cpp

CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/AESCryptographer.cpp > CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.i

CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/AESCryptographer.cpp -o CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.s

# Object files for target AES_128_CLI
AES_128_CLI_OBJECTS = \
"CMakeFiles/AES_128_CLI.dir/main.cpp.o" \
"CMakeFiles/AES_128_CLI.dir/Program.cpp.o" \
"CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o" \
"CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o"

# External object files for target AES_128_CLI
AES_128_CLI_EXTERNAL_OBJECTS =

AES_128_CLI: CMakeFiles/AES_128_CLI.dir/main.cpp.o
AES_128_CLI: CMakeFiles/AES_128_CLI.dir/Program.cpp.o
AES_128_CLI: CMakeFiles/AES_128_CLI.dir/FileManager.cpp.o
AES_128_CLI: CMakeFiles/AES_128_CLI.dir/AESCryptographer.cpp.o
AES_128_CLI: CMakeFiles/AES_128_CLI.dir/build.make
AES_128_CLI: CMakeFiles/AES_128_CLI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable AES_128_CLI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AES_128_CLI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AES_128_CLI.dir/build: AES_128_CLI
.PHONY : CMakeFiles/AES_128_CLI.dir/build

CMakeFiles/AES_128_CLI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AES_128_CLI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AES_128_CLI.dir/clean

CMakeFiles/AES_128_CLI.dir/depend:
	cd /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug /Users/ivaylokalaydzhiev/PDevelopment/AES-128-CLI/AES-128-CLI/cmake-build-debug/CMakeFiles/AES_128_CLI.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/AES_128_CLI.dir/depend

