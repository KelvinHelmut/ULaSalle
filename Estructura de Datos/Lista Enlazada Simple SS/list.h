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
        int max();
        int min();
        List* join(List *&list);
        List* intersection(List *&list);
    private:
        Node *head;
};

#endif
