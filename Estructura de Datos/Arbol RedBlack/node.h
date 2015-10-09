#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class T>
class Node {
    public:
        enum Color { RED, BLACK };
        Node(T value) : value(value), color(RED) {
            links[0] = links[1] = links[2] = 0;
        }
        T value;
        Color color;
        Node<T> *links[3];
};

#endif
