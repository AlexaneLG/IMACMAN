#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../include/Format.hpp"

/*Format class
  get information from std::strings and vectors of strings in different formats*/

/*create a single string from a vector of strings. Each substring is separated from the other by a delimiter
  return a string*/
std::string Format::formatToString(std::vector<std::string> string_vector, std::string delimiter)
{
  std::string single_string;
  for(int i = 0; i < string_vector.size(); i++)
  {
    single_string += string_vector[i] + delimiter;
  }

  return single_string;
}

/*create a vector of substrings from a single string. Each substring is separated from the other by a delimiter
  return a vector of strings*/
std::vector<std::string> Format::getSubstrings(std::string string, char delimiter)
{
  std::string substring;
  std::vector<std::string> substrings;
  std::istringstream is(string);
  while (getline(is, substring, delimiter))
  {
    substrings.push_back(substring);
  }
  return substrings;
}

/*detect if a substring is present inside a string.
return a bool : true if the substring is present in the string, false if not*/
bool Format::containsSubstring(std::string string, std::string substring)
{
  if(string.find(substring) == std::string::npos)
  {
    return false;
  }
  else return true;
}
