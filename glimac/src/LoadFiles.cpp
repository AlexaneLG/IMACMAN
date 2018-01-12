#include <iostream>
#include <string>
#include <vector>
#include "../include/LoadFiles.hpp"
#include "../include/FileManager.hpp"
#include "../include/File.hpp"
#include <stdexcept>
#include <fstream>

/*LoadFiles class :
provide static methods to load files from a path, or from by using information contained in other files*/

/*
Load a vector of Files (each containing information representing a Node) from a single File (listing the paths of each node file)
parameters: File graph_file, the source File
return: std::vector<File>
/*
Load a File from a string
parameters: std::string path, the path used to load the file
return: File
*/
File LoadFiles::loadFile(std::string path){
  File file;
  try{
    file = FileManager().load(path);
    std::cout <<"File loaded"<<std::endl;
  }
  catch(const std::exception &e){
    std::cerr << "error : " << e.what() <<std::endl;
    exit(EXIT_FAILURE);
  }
  return file;
}
