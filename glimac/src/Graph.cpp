#include "../include/Graph.h"

Graph::Graph() {}

Graph::Graph(std::string filePath) {
    std::ifstream file(filePath.c_str());

    if (file) {
        file >> _nbrNodes;
        for (int i = 0; i < _nbrNodes; i++)
            _graph.push_back(new Node(i));

        std::string cursor = "";
        while (std::getline(file, cursor)) {
            if (cursor != "") {
                std::stringstream line(cursor);
                int first = 0, second = 0;
                float weight = 0.0;
                line >> first;
                first--;
                line >> second;
                second--;
                line >> weight;

                _graph[first]->addSucc(_graph[second]);
                _graph[first]->addWeight(weight);
                _graph[second]->addSucc(_graph[first]);
                _graph[second]->addWeight(weight);
            }
        }
    } else {
        std::cout << "Erreur : Le fichier n'existe pas." << std::endl;
    }

}

Graph::~Graph() {
    for (auto x : _graph) {
        delete x;
    }
}

void Graph::print() {
    for (int i = 0; i < _nbrNodes; i++)
        _graph[i]->print();
}

std::vector<Node*> Graph::getGraph() {
    return _graph;
}

std::vector<std::vector<float>> Graph::toGhostTab() {
    std::vector<std::vector<float>> vec(68, std::vector<float>(68));
    for (int i = 0; i < 68; i++) {
        for (int j = 0; j < 68; j++) {
            vec[i][j] = -1.f;
        }
    }

    for (auto x: _graph) {
        int i = 0;
        for (auto y: x->getSuccs()) {
            vec[x->getTag()][y->getTag()] = x->getWeight(i);
            i++;
        }
    }
    return vec;
}