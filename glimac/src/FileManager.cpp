#include "../include/File.hpp"
#include "../include/FileManager.hpp"
#include <fstream>
#include <string>
#include <cstdio>
#include <stdexcept>

/*FileManager class :
load text files to a File object, write and remove text files using File object
 */

FileManager::FileManager(){}
FileManager::~FileManager(){}

 /*load the information from a file, using the file's path to read info from the file and copy it to a File object
 parameters : std::string path, the path to the file being loaded
 return: a File*/
File FileManager::load(std::string path){
  File file;
  file.setPath(path);
  //create a file stream to read from the file
  std::ifstream sourcefile(file.path());
  std::vector<std::string> data;

  if(!sourcefile.is_open()){
    throw std::runtime_error("unable to open file !");
  }
  else{
    std::string line_data;
    while(getline(sourcefile, line_data)){
        //get the content of each line in the file, one line corresponds to one element the data std::vector
        data.push_back(line_data);
      }
      sourcefile.close();
      file.setData(data);
  }
  return file;
}

/*write the information from a File to a text file
parameters : File file
return: void */
void FileManager::write(File file){
  std::ofstream targetfile(file.path());
  if (targetfile.is_open()){
    for(int i = 0; i < file.getData().size(); i++){
      targetfile << file.getData()[i] << std::endl; //each element in file.getData() corresponds to a line in the target file
    }
    targetfile.close();
  }
  else{
    throw std::runtime_error("unable to open file !");
  }
}

/*remove a file
parameters : File file
return: void */
void FileManager::removeFile(File file){
  const char * path = (file.path()).c_str();
  if(remove(path)!=0) throw std::runtime_error("file removal failed");
}
