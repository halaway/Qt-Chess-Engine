# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine/Build

# Utility rule file for ChessGame_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/ChessGame_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessGame_autogen.dir/progress.make

CMakeFiles/ChessGame_autogen: ChessGame_autogen/timestamp

ChessGame_autogen/timestamp: /usr/local/share/qt/libexec/moc
ChessGame_autogen/timestamp: /usr/local/share/qt/libexec/uic
ChessGame_autogen/timestamp: CMakeFiles/ChessGame_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ChessGame"
	/usr/local/Cellar/cmake/3.30.3/bin/cmake -E cmake_autogen /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine/Build/CMakeFiles/ChessGame_autogen.dir/AutogenInfo.json ""
	/usr/local/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine/Build/ChessGame_autogen/timestamp

ChessGame_autogen: CMakeFiles/ChessGame_autogen
ChessGame_autogen: ChessGame_autogen/timestamp
ChessGame_autogen: CMakeFiles/ChessGame_autogen.dir/build.make
.PHONY : ChessGame_autogen

# Rule to build all files generated by this target.
CMakeFiles/ChessGame_autogen.dir/build: ChessGame_autogen
.PHONY : CMakeFiles/ChessGame_autogen.dir/build

CMakeFiles/ChessGame_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChessGame_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChessGame_autogen.dir/clean

CMakeFiles/ChessGame_autogen.dir/depend:
	cd /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine/Build /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine/Build /Users/donnie/Desktop/Chess-Folder/Qt-Chess-Engine/Build/CMakeFiles/ChessGame_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ChessGame_autogen.dir/depend

