#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>

using std::cout;
using std::endl;

template<class T>
class Tree {
    public:
        Tree() : root(0) {}
        bool find(T value, Node<T> **&p);
        void add(T value);
        void print();
        Node<T>* parent(T value);
        Node<T>* brother(T value);
        Node<T>* uncle(T value);
        Node<T>* gparent(T value);
        int count();
        int countLeaf();
        int countEven();
    private:
        void order(Node<T> *&node);
        int count(Node<T> *&node);
        int countLeaf(Node<T> *&node);
        int countEven(Node<T> *&node);
        Node<T> *root;
};

template<class T>
void Tree<T>::add(T value) {
    Node<T> **p;

    if (!find(value, p))
        *p = new Node<T>(value);
}

template<class T>
bool Tree<T>::find(T value, Node<T> **&p) {
    p = &root;

    while (*p) {
        if ((*p)->value == value) return true;
        p = &((*p)->childs[(*p)->value < value]);
    }

    return false;
}

template<class T>
void Tree<T>::print() {
    order(root);
    cout << endl;
}

template<class T>
void Tree<T>::order(Node<T> *&node) {
    if (node->childs[0])
        order(node->childs[0]);

    cout << node->value << " ";

    if (node->childs[1])
        order(node->childs[1]);
}

template<class T>
int Tree<T>::count() {
    return count(root);
}

template<class T>
int Tree<T>::count(Node<T> *&node) {
    return (!node) ? 0 : 1 + count(node->childs[0]) + count(node->childs[1]);
}

template<class T>
int Tree<T>::countLeaf() {
    return countLeaf(root);
}

template<class T>
int Tree<T>::countLeaf(Node<T> *&node) {
    return (!node) ? 0 : (!node->childs[0] && !node->childs[1]) +
            countLeaf(node->childs[0]) + countLeaf(node->childs[1]);
}

template<class T>
int Tree<T>::countEven() {
    return countEven(root);
}

template<class T>
int Tree<T>::countEven(Node<T> *&node) {
    return (!node) ? 0 : (node->value % 2 == 0) +
            countEven(node->childs[0]) + countEven(node->childs[1]);
}

template<class T>
Node<T>* Tree<T>::parent(T value) {
    Node<T> *node = root;
    Node<T> *parent = 0;

    while (node) {
        if (node->value == value) return parent;
        parent = node;
        node = node->childs[node->value < value];
    }
    
    return 0;
}

template<class T>
Node<T>* Tree<T>::brother(T value) {
    Node<T> *parent = this->parent(value);
    return (parent) ? parent->childs[parent->value > value] : 0;
}

template<class T>
Node<T>* Tree<T>::uncle(T value) {
    Node<T> *parent = this->parent(value);
    return (parent) ? brother(parent->value) : 0;
}

template<class T>
Node<T>* Tree<T>::gparent(T value) {
    Node<T> *parent = this->parent(value);
    return (parent) ? this->parent(parent->value) : 0;
}

#endif
