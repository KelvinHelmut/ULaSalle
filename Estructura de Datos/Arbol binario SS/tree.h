#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

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
        void removeNodeLeaf(T value);
        void removeNode1Child(T value);
        void removeNode2Childs(T value);
        void removeAll();
        void printPreOrderIterative();
        void printLevels();
        T max();
        void printDot(char*);
    private:
        void inOrder(Node<T> *&node);
        void preOrder(Node<T> *&node);
        void posOrder(Node<T> *&node);
        int count(Node<T> *&node);
        int countLeaf(Node<T> *&node);
        int countEven(Node<T> *&node);
        T max(Node<T> **&p);
        void printDot(Node<T>*, std::ostream&);
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
    inOrder(root);
    cout << endl;
}

template<class T>
void Tree<T>::preOrder(Node<T> *&node) {
    cout << node->value << " ";
    if (node->childs[0]) preOrder(node->childs[0]);
    if (node->childs[1]) preOrder(node->childs[1]);
}

template<class T>
void Tree<T>::inOrder(Node<T> *&node) {
    if (node->childs[0]) inOrder(node->childs[0]);
    cout << node->value << " ";
    if (node->childs[1]) inOrder(node->childs[1]);
}

template<class T>
void Tree<T>::posOrder(Node<T> *&node) {
    if (node->childs[0]) posOrder(node->childs[0]);
    if (node->childs[1]) posOrder(node->childs[1]);
    cout << node->value << " ";
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

template<class T>
void Tree<T>::printPreOrderIterative() {
    if (!root) return;

    std::stack<Node<T>*> stack;
    Node<T> *tmp;
    stack.push(root);

    while (!stack.empty()) {
        tmp = stack.top();
        stack.pop();
        cout << tmp->value << " ";
        if (tmp->childs[0]) stack.push(tmp->childs[0]);
        if (tmp->childs[1]) stack.push(tmp->childs[1]);
    }
    cout << endl;
}

template<class T>
void Tree<T>::printLevels() {
    if (!root) return;

    std::queue<Node<T>*> queue;
    Node<T> *tmp;
    queue.push(root);

    while (!queue.empty()) {
        tmp = queue.front();
        queue.pop();
        cout << tmp->value << " ";
        if (tmp->childs[0]) queue.push(tmp->childs[0]);
        if (tmp->childs[1]) queue.push(tmp->childs[1]);
    }
    cout << endl;
}

template<class T>
void Tree<T>::removeNodeLeaf(T value) {
    Node<T> **p;
    if (!find(value, p)) return;
    if ((*p)->childs[0] || (*p)->childs[1]) return;

    delete *p;
    *p = 0;
}

template<class T>
void Tree<T>::removeNode1Child(T value) {
    Node<T> **p;
    Node<T> *tmp;
    if (!find(value, p)) return;

    tmp = ((*p)->childs[0] && !(*p)->childs[1]) ? (*p)->childs[0] :
        ((*p)->childs[1] && !(*p)->childs[0]) ? (*p)->childs[1] : 0;
    if (!tmp) return;
    delete *p;
    *p = tmp;
}

template<class T>
void Tree<T>::removeNode2Childs(T value) {
    Node<T> **p;
    if (!find(value, p)) return;
    if (!((*p)->childs[0] && (*p)->childs[1])) return;

    Node<T> **m = &((*p)->childs[0]);
    Node<T> *tmp;
    cout << max(m) << endl;
    cout << (*m)->value << endl;
    (*p)->value = (*m)->value;
    tmp = (*m)->childs[0];
    delete *m;
    *m = tmp;
}

template<class T>
T Tree<T>::max(Node<T> **&p) {
    if (!(*p)) T();
    while ((*p)->childs[1])
        p = &((*p)->childs[1]);

    return (*p)->value;
}

template<class T>
T Tree<T>::max() {
    Node<T> **p = &root;
    return max(p);
}

template<class T>
void Tree<T>::printDot(char* name) {
    std::ofstream out(name);
    out << "digraph G {" << endl;
    printDot(root, out);
    out << "}";
}

template<class T>
void Tree<T>::printDot(Node<T> *node, std::ostream &out) {
    if (!node) return;
    if (node->childs[0])
        out << node->value << "->" << node->childs[0]->value << endl;
    if (node->childs[1])
        out << node->value << "->" << node->childs[1]->value << endl;
    printDot(node->childs[0], out);
    printDot(node->childs[1], out);
}

#endif
