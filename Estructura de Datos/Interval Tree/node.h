#ifndef NODE_H
#define NODE_H

#include <ostream>

template<class T>
class Node {
    public:
        Node(T min, T max) : red(1) {
            values[0] = min;
            values[2] = values[1] = max;
            links[0] = links[1] = links[2] = 0;
        }
        T values[3];
        bool red;
        Node<T> * links[3];

        friend std::ostream & operator << (std::ostream &out, const Node<T> * node) {
            if (!node) {
                out << "NULL";
            } else
            out << "\"[" << node->values[0] << ","
                << node->values[1] << "] (" << node->values[2] << ")\"";
            return out;
        }
};

#endif
