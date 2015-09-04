#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class T>
class Node {
    public:
        Node(T value) : value(value) { childs[0] = childs[1] = 0; }
        T value;
        Node *childs[2];

        friend std::ostream& operator << (std::ostream &out, const Node<T> *node) {
            if (node)
                out << node->value;
            else 
                out << "No existe";
            return out;
        }
};

#endif
