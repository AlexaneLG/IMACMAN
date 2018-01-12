#include "../include/File.hpp"
#include <string>
#include <vector>

/*File class :
contains information to write to or read from text files :
a std::string m_path representing the path to the file
and a std::vector of strings m_data representing the data contained in the File*/

File::File(std::string path, std::vector<std::string> data): m_path(path), m_data(data){}

File::File(): m_path(" "){
}

//getters
std::vector<std::string> File::getData() const{
  return m_data;
}

std::string File::path() const{
  return m_path;
}

//setters
void File::setData(const std::vector<std::string> &data){
  m_data = data;
}
void File::setPath(const std::string path){
  m_path = path;
}
