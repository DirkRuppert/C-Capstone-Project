# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/dirk/development/projects/CppND-Capstone-Snake-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dirk/development/projects/CppND-Capstone-Snake-Game/build

# Include any dependencies generated for this target.
include CMakeFiles/SnakeGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SnakeGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SnakeGame.dir/flags.make

CMakeFiles/SnakeGame.dir/src/main.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SnakeGame.dir/src/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/main.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/main.cpp

CMakeFiles/SnakeGame.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/main.cpp > CMakeFiles/SnakeGame.dir/src/main.cpp.i

CMakeFiles/SnakeGame.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/main.cpp -o CMakeFiles/SnakeGame.dir/src/main.cpp.s

CMakeFiles/SnakeGame.dir/src/game.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SnakeGame.dir/src/game.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/game.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/game.cpp

CMakeFiles/SnakeGame.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/game.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/game.cpp > CMakeFiles/SnakeGame.dir/src/game.cpp.i

CMakeFiles/SnakeGame.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/game.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/game.cpp -o CMakeFiles/SnakeGame.dir/src/game.cpp.s

CMakeFiles/SnakeGame.dir/src/level.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/level.cpp.o: ../src/level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SnakeGame.dir/src/level.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/level.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/level.cpp

CMakeFiles/SnakeGame.dir/src/level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/level.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/level.cpp > CMakeFiles/SnakeGame.dir/src/level.cpp.i

CMakeFiles/SnakeGame.dir/src/level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/level.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/level.cpp -o CMakeFiles/SnakeGame.dir/src/level.cpp.s

CMakeFiles/SnakeGame.dir/src/controller.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SnakeGame.dir/src/controller.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/controller.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/controller.cpp

CMakeFiles/SnakeGame.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/controller.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/controller.cpp > CMakeFiles/SnakeGame.dir/src/controller.cpp.i

CMakeFiles/SnakeGame.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/controller.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/controller.cpp -o CMakeFiles/SnakeGame.dir/src/controller.cpp.s

CMakeFiles/SnakeGame.dir/src/renderer.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SnakeGame.dir/src/renderer.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/renderer.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/renderer.cpp

CMakeFiles/SnakeGame.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/renderer.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/renderer.cpp > CMakeFiles/SnakeGame.dir/src/renderer.cpp.i

CMakeFiles/SnakeGame.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/renderer.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/renderer.cpp -o CMakeFiles/SnakeGame.dir/src/renderer.cpp.s

CMakeFiles/SnakeGame.dir/src/player.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/player.cpp.o: ../src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SnakeGame.dir/src/player.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/player.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/player.cpp

CMakeFiles/SnakeGame.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/player.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/player.cpp > CMakeFiles/SnakeGame.dir/src/player.cpp.i

CMakeFiles/SnakeGame.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/player.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/player.cpp -o CMakeFiles/SnakeGame.dir/src/player.cpp.s

CMakeFiles/SnakeGame.dir/src/map.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/map.cpp.o: ../src/map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SnakeGame.dir/src/map.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/map.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/map.cpp

CMakeFiles/SnakeGame.dir/src/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/map.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/map.cpp > CMakeFiles/SnakeGame.dir/src/map.cpp.i

CMakeFiles/SnakeGame.dir/src/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/map.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/map.cpp -o CMakeFiles/SnakeGame.dir/src/map.cpp.s

CMakeFiles/SnakeGame.dir/src/ghost.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/ghost.cpp.o: ../src/ghost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SnakeGame.dir/src/ghost.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/ghost.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/ghost.cpp

CMakeFiles/SnakeGame.dir/src/ghost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/ghost.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/ghost.cpp > CMakeFiles/SnakeGame.dir/src/ghost.cpp.i

CMakeFiles/SnakeGame.dir/src/ghost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/ghost.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/ghost.cpp -o CMakeFiles/SnakeGame.dir/src/ghost.cpp.s

CMakeFiles/SnakeGame.dir/src/gameObject.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/gameObject.cpp.o: ../src/gameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SnakeGame.dir/src/gameObject.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/gameObject.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/gameObject.cpp

CMakeFiles/SnakeGame.dir/src/gameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/gameObject.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/gameObject.cpp > CMakeFiles/SnakeGame.dir/src/gameObject.cpp.i

CMakeFiles/SnakeGame.dir/src/gameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/gameObject.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/gameObject.cpp -o CMakeFiles/SnakeGame.dir/src/gameObject.cpp.s

CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.o: ../src/updateHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.o -c /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/updateHandler.cpp

CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/updateHandler.cpp > CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.i

CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dirk/development/projects/CppND-Capstone-Snake-Game/src/updateHandler.cpp -o CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.s

# Object files for target SnakeGame
SnakeGame_OBJECTS = \
"CMakeFiles/SnakeGame.dir/src/main.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/game.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/level.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/controller.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/renderer.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/player.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/map.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/ghost.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/gameObject.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.o"

# External object files for target SnakeGame
SnakeGame_EXTERNAL_OBJECTS =

SnakeGame: CMakeFiles/SnakeGame.dir/src/main.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/game.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/level.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/controller.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/renderer.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/player.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/map.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/ghost.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/gameObject.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/updateHandler.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/build.make
SnakeGame: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
SnakeGame: CMakeFiles/SnakeGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable SnakeGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SnakeGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SnakeGame.dir/build: SnakeGame

.PHONY : CMakeFiles/SnakeGame.dir/build

CMakeFiles/SnakeGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SnakeGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SnakeGame.dir/clean

CMakeFiles/SnakeGame.dir/depend:
	cd /home/dirk/development/projects/CppND-Capstone-Snake-Game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dirk/development/projects/CppND-Capstone-Snake-Game /home/dirk/development/projects/CppND-Capstone-Snake-Game /home/dirk/development/projects/CppND-Capstone-Snake-Game/build /home/dirk/development/projects/CppND-Capstone-Snake-Game/build /home/dirk/development/projects/CppND-Capstone-Snake-Game/build/CMakeFiles/SnakeGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SnakeGame.dir/depend
