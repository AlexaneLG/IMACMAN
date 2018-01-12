#include "../include/GhostStrategy.h"
#include <vector>

void Move::setStrategy(int type) {
    delete strategy_;
    if (type == Dijkstra)
        strategy_ = new DijkstraStrategy();
    /*else if (type == Random)
        strategy_ = new RandomStrategy();
    else if (type == Follow)
        strategy_ = new FollowStrategy();
    else if (type == Escape)
        strategy_ = new EscapeStrategy;*/
}

void Move::execute() {
    strategy_->movement();
}

/*void Move::setGraph(Graph* graph) {
    _graph = graph;
}*/
