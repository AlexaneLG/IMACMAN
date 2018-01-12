#pragma once
#include "File.hpp"
#include <fstream>
#include <string>
class FileManager{

public:
  FileManager();
  ~FileManager();
  File load(std::string path);
  void write(File file);
  void removeFile(File file);

};
