#ifndef GRAPH2_NODE_H
#define GRAPH2_NODE_H

#include <iostream>
#include <vector>
#include <string>

class Node {
private:
    int _tag;
    std::vector<float> _weights;
    std::vector<Node*> _succs;
public:
    Node();
    Node(int tag);
    int getTag();
    void setTag(int tag);
    float getWeight(int index);
    Node* getSucc(int index);
    std::vector<Node*> getSuccs();
    void addWeight(float weight);
    void addSucc(Node* node);
    void print();
};


#endif //GRAPH2_NODE_H
