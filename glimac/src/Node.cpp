#include "../include/Node.h"

Node::Node() : _tag(0) {}

Node::Node(int tag) : _tag(tag) {}

float Node::getWeight(int index) {
    return *(_weights.begin() + index);
}

Node* Node::getSucc(int index) {
    return *(_succs.begin() + index);
}

int Node::getTag() {
    return _tag;
}

void Node::setTag(int tag) {
    _tag = tag;
}

void Node::addWeight(float poids) {
    _weights.push_back(poids);
}

void Node::addSucc(Node* node) {
    _succs.push_back(node);
}

std::vector<Node*> Node::getSuccs() {
    return _succs;
}

void Node::print() {
    std::cout << "Noeud " << _tag << " :\n\tSuccesseurs :";
    for (int i = 0; i < _succs.size(); i++)
         std::cout << " " << _succs[i]->_tag;
    std:: cout << "\n\tPoids :";
    for (int i = 0; i < _weights.size(); i++)
        std::cout << " " << _weights[i];
    std::cout << std::endl;
}