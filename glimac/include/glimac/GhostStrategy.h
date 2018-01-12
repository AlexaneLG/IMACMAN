#ifndef DIJKSTRA_GHOSTSTRATEGY_H
#define DIJKSTRA_GHOSTSTRATEGY_H

#include "Graph.h"
#include "Dijkstra.h"

class GhostStrategy;

class Move {
public:
    enum StrategyType {
        Dijkstra, Random, Follow, Escape
    };

    Move() {
        strategy_ = nullptr;
    }
    void setStrategy(int type);
    void execute();
private:
    GhostStrategy *strategy_;
};

class GhostStrategy {
public:
    GhostStrategy() {}
    ~GhostStrategy() {
        delete _graph;
        //delete[] _ghostGraph;
        //delete _ghostGraph;
    }
    void movement() {
        //CODE
        _graph = new Graph("graph.txt");
        _ghostGraph = _graph->toGhostTab();

        loadStrategy();
        //parcours graph

        //aller au noeud

    }
protected:
    Graph* _graph;
    std::vector<std::vector<float>> _ghostGraph;
private:
    virtual void loadStrategy() =0;
};

class DijkstraStrategy: public GhostStrategy {
public:
    DijkstraStrategy() {}
private:
    void loadStrategy() override {
        std::vector<int> close;
        std::vector<std::vector<Dijkstra*>> ghostDijkstra(68, std::vector<Dijkstra*>(68));

        Dijkstra dijkstra;
        dijkstra.algorithmDijkstra(_ghostGraph, 0, ghostDijkstra, close);
        dijkstra.printDijkstra(ghostDijkstra, close);
    }
};

class RandomStrategy: public GhostStrategy {
public:
    RandomStrategy() {}
private:
};

class FollowStrategy: public GhostStrategy {
public:
    FollowStrategy() {}
private:
};

class EscapeStrategy: public GhostStrategy {
public:
    EscapeStrategy() {}
private:
};

#endif //DIJKSTRA_GHOSTSTRATEGY_H
