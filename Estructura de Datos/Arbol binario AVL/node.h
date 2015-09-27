#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class T>
class Node {
    public:
        Node(T value) : value(value), factor(0) { childs[0] = childs[1] = 0; }
        T value;
        int factor;
        Node *childs[2];
};

#endif
