# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN"

# Include any dependencies generated for this target.
include TP3/CMakeFiles/TP3_dessin_terre.dir/depend.make

# Include the progress variables for this target.
include TP3/CMakeFiles/TP3_dessin_terre.dir/progress.make

# Include the compile flags for this target's objects.
include TP3/CMakeFiles/TP3_dessin_terre.dir/flags.make

TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o: TP3/CMakeFiles/TP3_dessin_terre.dir/flags.make
TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o: TP3/dessin_terre.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o"
	cd "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o -c "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3/dessin_terre.cpp"

TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.i"
	cd "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3/dessin_terre.cpp" > CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.i

TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.s"
	cd "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3/dessin_terre.cpp" -o CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.s

TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o.requires:

.PHONY : TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o.requires

TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o.provides: TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o.requires
	$(MAKE) -f TP3/CMakeFiles/TP3_dessin_terre.dir/build.make TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o.provides.build
.PHONY : TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o.provides

TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o.provides.build: TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o


# Object files for target TP3_dessin_terre
TP3_dessin_terre_OBJECTS = \
"CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o"

# External object files for target TP3_dessin_terre
TP3_dessin_terre_EXTERNAL_OBJECTS =

TP3/TP3_dessin_terre: TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o
TP3/TP3_dessin_terre: TP3/CMakeFiles/TP3_dessin_terre.dir/build.make
TP3/TP3_dessin_terre: glimac/libglimac.a
TP3/TP3_dessin_terre: TP3/CMakeFiles/TP3_dessin_terre.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP3_dessin_terre"
	cd "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP3_dessin_terre.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP3/CMakeFiles/TP3_dessin_terre.dir/build: TP3/TP3_dessin_terre

.PHONY : TP3/CMakeFiles/TP3_dessin_terre.dir/build

TP3/CMakeFiles/TP3_dessin_terre.dir/requires: TP3/CMakeFiles/TP3_dessin_terre.dir/dessin_terre.cpp.o.requires

.PHONY : TP3/CMakeFiles/TP3_dessin_terre.dir/requires

TP3/CMakeFiles/TP3_dessin_terre.dir/clean:
	cd "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3" && $(CMAKE_COMMAND) -P CMakeFiles/TP3_dessin_terre.dir/cmake_clean.cmake
.PHONY : TP3/CMakeFiles/TP3_dessin_terre.dir/clean

TP3/CMakeFiles/TP3_dessin_terre.dir/depend:
	cd "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN" "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3" "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN" "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3" "/home/titlois/Documents/s3/Synthèse d'images/projet/IMACMAN/TP3/CMakeFiles/TP3_dessin_terre.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : TP3/CMakeFiles/TP3_dessin_terre.dir/depend

