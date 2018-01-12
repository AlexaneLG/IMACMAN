#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include "Graph.h"

class Dijkstra {
public:
    Dijkstra();
    Dijkstra(int value, int previous);
    ~Dijkstra();

    int getValue() const;
    int getPrevious() const;

    void setValue(int value);
    void setPrevious(int previous);

    bool estDansFerme(int node, std::vector<int> close);
    void algorithmDijkstra(std::vector<std::vector<float>> graph, int source, std::vector<std::vector<Dijkstra*>> & dijkstra, std::vector<int> & close);
    int noeudMin(std::vector<std::vector<Dijkstra*>> dijkstra, Dijkstra* curseur, int i);
    void printDijkstra(std::vector<std::vector<Dijkstra*>> dijkstra, std::vector<int> close);

private:
    float _value;
    int _previous;
};


#endif //DIJKSTRA_DIJKSTRA_H
