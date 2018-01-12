#include <stdexcept>
#include "../include/Import.hpp"
#include "../include/File.hpp"
#include "../include/Format.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include "GameGrid.hpp"

/*Import class :
Import or "translate" information from Files and strings to game objects such as GameGrid */

/*
Import a vector of Nodes from a vector of Files
parameters: std::vector<File> node_files, the source vector of Files
return: a std::vector of Nodes
*/

GameGrid Import::mazeGridFromFile(const File &file){
    GameGrid grid;
    std::vector<int> elements;
    std::vector<std::string> substrings;
    for(int i=0; i < file.getData().size(); i++){
        substrings = Format::getSubstrings(file.getData()[i], ' ');
        for(int j = 0; j < substrings.size(); j++){
            elements.push_back(stoi(substrings[j]));
        }
    }
    int nbCols = substrings.size();
    int nbRows = file.getData().size();
    grid.setNbCols(nbCols);
    grid.setNbRows(nbRows);
    grid.setElements(elements);
    return grid;
}