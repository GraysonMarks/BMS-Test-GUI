# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /home/pie/st/stm32cubeclt_1.18.0/CMake/bin/cmake

# The command to remove a file.
RM = /home/pie/st/stm32cubeclt_1.18.0/CMake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pie/Documents/BMS-Test-GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pie/Documents/BMS-Test-GUI/build

# Utility rule file for BMSTestGUI_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/BMSTestGUI_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BMSTestGUI_autogen.dir/progress.make

CMakeFiles/BMSTestGUI_autogen: BMSTestGUI_autogen/timestamp

BMSTestGUI_autogen/timestamp: /usr/lib/qt6/libexec/moc
BMSTestGUI_autogen/timestamp: CMakeFiles/BMSTestGUI_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/pie/Documents/BMS-Test-GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target BMSTestGUI"
	/home/pie/st/stm32cubeclt_1.18.0/CMake/bin/cmake -E cmake_autogen /home/pie/Documents/BMS-Test-GUI/build/CMakeFiles/BMSTestGUI_autogen.dir/AutogenInfo.json ""
	/home/pie/st/stm32cubeclt_1.18.0/CMake/bin/cmake -E touch /home/pie/Documents/BMS-Test-GUI/build/BMSTestGUI_autogen/timestamp

BMSTestGUI_autogen: BMSTestGUI_autogen/timestamp
BMSTestGUI_autogen: CMakeFiles/BMSTestGUI_autogen
BMSTestGUI_autogen: CMakeFiles/BMSTestGUI_autogen.dir/build.make
.PHONY : BMSTestGUI_autogen

# Rule to build all files generated by this target.
CMakeFiles/BMSTestGUI_autogen.dir/build: BMSTestGUI_autogen
.PHONY : CMakeFiles/BMSTestGUI_autogen.dir/build

CMakeFiles/BMSTestGUI_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BMSTestGUI_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BMSTestGUI_autogen.dir/clean

CMakeFiles/BMSTestGUI_autogen.dir/depend:
	cd /home/pie/Documents/BMS-Test-GUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pie/Documents/BMS-Test-GUI /home/pie/Documents/BMS-Test-GUI /home/pie/Documents/BMS-Test-GUI/build /home/pie/Documents/BMS-Test-GUI/build /home/pie/Documents/BMS-Test-GUI/build/CMakeFiles/BMSTestGUI_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/BMSTestGUI_autogen.dir/depend

