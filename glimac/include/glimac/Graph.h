#ifndef GRAPH2_GRAPH_H
#define GRAPH2_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Node.h"

class Graph {
private:
    std::vector<Node*> _graph;
    unsigned int _nbrNodes;
public:
    Graph();
    Graph(std::string filePath);
    ~Graph();
    void print();
    std::vector<Node*> getGraph();
    std::vector<std::vector<float>> toGhostTab();
};


#endif //GRAPH2_GRAPH_H
