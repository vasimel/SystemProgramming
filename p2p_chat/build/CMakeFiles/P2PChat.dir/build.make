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
CMAKE_SOURCE_DIR = /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build

# Include any dependencies generated for this target.
include CMakeFiles/P2PChat.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/P2PChat.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/P2PChat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P2PChat.dir/flags.make

CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o: CMakeFiles/P2PChat.dir/flags.make
CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o: P2PChat_autogen/mocs_compilation.cpp
CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o: CMakeFiles/P2PChat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o -MF CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o -c /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build/P2PChat_autogen/mocs_compilation.cpp

CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build/P2PChat_autogen/mocs_compilation.cpp > CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.i

CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build/P2PChat_autogen/mocs_compilation.cpp -o CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.s

CMakeFiles/P2PChat.dir/main.cpp.o: CMakeFiles/P2PChat.dir/flags.make
CMakeFiles/P2PChat.dir/main.cpp.o: ../main.cpp
CMakeFiles/P2PChat.dir/main.cpp.o: CMakeFiles/P2PChat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/P2PChat.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P2PChat.dir/main.cpp.o -MF CMakeFiles/P2PChat.dir/main.cpp.o.d -o CMakeFiles/P2PChat.dir/main.cpp.o -c /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/main.cpp

CMakeFiles/P2PChat.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P2PChat.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/main.cpp > CMakeFiles/P2PChat.dir/main.cpp.i

CMakeFiles/P2PChat.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P2PChat.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/main.cpp -o CMakeFiles/P2PChat.dir/main.cpp.s

# Object files for target P2PChat
P2PChat_OBJECTS = \
"CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/P2PChat.dir/main.cpp.o"

# External object files for target P2PChat
P2PChat_EXTERNAL_OBJECTS =

P2PChat: CMakeFiles/P2PChat.dir/P2PChat_autogen/mocs_compilation.cpp.o
P2PChat: CMakeFiles/P2PChat.dir/main.cpp.o
P2PChat: CMakeFiles/P2PChat.dir/build.make
P2PChat: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
P2PChat: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
P2PChat: CMakeFiles/P2PChat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable P2PChat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P2PChat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P2PChat.dir/build: P2PChat
.PHONY : CMakeFiles/P2PChat.dir/build

CMakeFiles/P2PChat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P2PChat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P2PChat.dir/clean

CMakeFiles/P2PChat.dir/depend:
	cd /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build /home/vasilina/Documents/hse_studies/SystemProgramming/p2p_chat/build/CMakeFiles/P2PChat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P2PChat.dir/depend

