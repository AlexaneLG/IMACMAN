#pragma once
#include <vector>
#include <string>

class File{
private:
  //FilePath m_path;
  std::string m_path;
  std::vector<std::string> m_data;

public:
  File(std::string path, std::vector<std::string> data);
  File();

  //getters
  std::vector<std::string> getData() const;
  std::string path() const;

  //setters
  void setData(const std::vector<std::string> &data);
  void setPath(const std::string path);
};
