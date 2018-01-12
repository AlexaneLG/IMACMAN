#include <iostream>
#include "../include/Graph.h"
#include "../include/Dijkstra.h"
#include "../include/GhostStrategy.h"

int main() {
    Graph* graph = new Graph("graph.txt");
    std::vector<std::vector<float>> ghostGraph = graph->toGhostTab();

    std::vector<int> close;
    std::vector<std::vector<Dijkstra*>> ghostDijkstra(68, std::vector<Dijkstra*>(68));

    Dijkstra dijkstra;
    dijkstra.algorithmDijkstra(ghostGraph, 0, ghostDijkstra, close);
    dijkstra.printDijkstra(ghostDijkstra, close);

    delete graph;

    /*Move ghostMovement;
    ghostMovement.setStrategy(1);
    ghostMovement.execute();*/


    return 0;
}