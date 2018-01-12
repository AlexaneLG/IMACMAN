include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(glimac ${SRC_FILES} src/pacmanShape.cpp include/glimac/pacmanShape.h include/glimac/Box.hpp src/Box.cpp include/GameGrid.hpp src/GridCell.cpp src/GridCell.hpp src/GameElement.cpp src/GameElement.hpp src/Pacman.cpp src/Pacman.hpp)
