#include "../include/Dijkstra.h"

Dijkstra::Dijkstra() {}

Dijkstra::Dijkstra(int value, int previous) : _value(value), _previous(previous) {}

int Dijkstra::getValue() const {
    return this->_value;
}

int Dijkstra::getPrevious() const {
    return this->_previous;
}

void Dijkstra::setValue(int value) {
    this->_value = value;
}

void Dijkstra::setPrevious(int previous) {
    this->_previous = previous;
}

void Dijkstra::algorithmDijkstra(std::vector<std::vector<float>> graph, int source, std::vector<std::vector<Dijkstra*>> & dijkstra, std::vector<int> & close) {
    int noeud = 0;
    int index = source;
    Dijkstra* curseur = new Dijkstra();

    // initialisation
    close.push_back(index);
    dijkstra[0][index] = new Dijkstra(0, -1);
    noeud = index;
    for (int i = 0; i < 68; i++) {
        index = i;
        if (estDansFerme(i, close) == false) {
            dijkstra[0][i] = new Dijkstra;
            if (graph[noeud][i] != -1) {
                dijkstra[0][i]->_value = graph[noeud][i];
                dijkstra[0][i]->_previous = source;
            } else {
                dijkstra[0][i]->_value = -1;
                dijkstra[0][i]->_previous = -1;
            }
        }
    }

    for (int i = 1; i < 68; i++) {
        source = noeudMin(dijkstra, curseur, i - 1);
        if (source == -1)
            break;
        noeud = source;
        close.push_back(source);

        for (int j = 0; j < 68; j++) {
            index = j;
            if (estDansFerme(index, close) == 0) { //si le noeud etudie n est pas dans ferme
                dijkstra[i][j] = new Dijkstra;
                if (dijkstra[i - 1][j]->_value == -1) { // a l etape precedente il n y avait pas de chemin jusqu a ce noeud
                    if (graph[noeud][j] != -1) {
                        dijkstra[i][j]->_value = graph[noeud][j] + curseur->_value;
                        dijkstra[i][j]->_previous = source;
                    } else {
                        dijkstra[i][j]->_value = -1;
                        dijkstra[i][j]->_previous = -1;
                    }
                } else {
                    if (graph[noeud][j] != -1 && curseur != nullptr && (graph[noeud][j] + curseur->_value) < dijkstra[i - 1][j]->_value) {
                        dijkstra[i][j]->_value = graph[noeud][j]  + curseur->_value;
                        dijkstra[i][j]->_previous = source;
                    } else {
                        dijkstra[i][j]->_value = dijkstra[i - 1][j]->_value;
                        dijkstra[i][j]->_previous = dijkstra[i - 1][j]->_previous;
                    }
                }
            }
        }
    }
}

bool Dijkstra::estDansFerme(int node, std::vector<int> close) {
    int i = 0, ctrl = false;
    for (i = 0; i < close.size() ; i++) {
        if (close[i] == node)
            ctrl = true;
    }
    return ctrl; //le noeud est dans ferme
}

int Dijkstra::noeudMin(std::vector<std::vector<Dijkstra*>> dijkstra, Dijkstra* curseur, int i) {
    int j = 0, min = 1000;
    char noeudMin = -1;
    for (j = 0; j < 68; j++) {
        if (dijkstra[i][j] != nullptr) {
            if (dijkstra[i][j]->_previous != -1 && dijkstra[i][j]->_value < min) {
                noeudMin = j;
                curseur->_value = dijkstra[i][j]->_value;
                curseur->_previous = dijkstra[i][j]->_previous;
                min = dijkstra[i][j]->_value;
            }
        }
    }
    return noeudMin;
}

void Dijkstra::printDijkstra(std::vector<std::vector<Dijkstra*>> dijkstra, std::vector<int> close) {
    std::string etape = "";
    for (int i = 0; i < 68; i++) {
        std::cout << std::setw(5) << std::right << i << "|";
    }
    std::cout << std::endl;

    for (int i = 0; i < close.size(); i++) {
        etape += std::to_string(close[i]);
        etape += "-";
        for (int j = 0; j < 68; j++) {
            if (dijkstra[i][j] == nullptr)
                std::cout << "      /|";
            else
                std::cout << std::setw(3) << std::right <<dijkstra[i][j]->_value << "_" << std::setw(3) << std::left << dijkstra[i][j]->_previous << "|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << etape << std::endl;
}

Dijkstra::~Dijkstra() {

}