#pragma once
#include "File.hpp"
#include <vector>
#include <string>
#include "GameGrid.hpp"

class Import{
private:

public:
  static GameGrid mazeGridFromFile(const File &file);
};
