#ifndef LIST_H
#define LIST_H

#include "node.h"

#include <iostream>

using std::cout;
using std::endl;

class List {
    public:
        List() : head(0) {}
        ~List() {}
        void add(int value);
        bool find(int value, Node **&node);
        void print();
        void reverse();
    private:
        Node *head;
};

#endif
