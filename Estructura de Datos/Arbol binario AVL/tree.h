#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>
#include <fstream>
#include <stack>

using std::cout;
using std::endl;

template<class T>
class Tree {
    public:
        Tree() : root(0) {}
        bool find(T value, Node<T> **&p);
        void add(T value);
        void printDot(char*);
    private:
        void rs(Node<T> *&p, bool);
        void rd(Node<T> *&p, bool);
        void printDot(Node<T>*, std::ostream&);
        Node<T> *root;
};

template<class T>
void Tree<T>::add(T value) {
    Node<T> **p = &root;
    std::stack<Node<T>**> nodes;
    std::stack<int> factors;
    int tmp = 0;

    while (*p) {
        if ((*p)->value == value) return;
        nodes.push(p);
        factors.push((*p)->value < value);
        p = &((*p)->childs[(*p)->value < value]);
    }

    *p = new Node<T>(value);
    
    while (!nodes.empty()) {
        (*nodes.top())->factor += factors.top() * 2 - 1;
        if ((*nodes.top())->factor == 2 || (*nodes.top())->factor == -2) {
                rs((*nodes.top()), factors.top());
                return;
            if ((factors.top() > 0  && tmp > 0) || (factors.top() < 0  && tmp < 0))
                rs((*nodes.top()), factors.top());
            else 
                rd((*nodes.top()), factors.top());
            return;
        } else if (!(*nodes.top())->factor)
            return;
        tmp = factors.top();
        nodes.pop();
        factors.pop();
    }
}

template<class T>
void Tree<T>::rs(Node<T> *&p, bool b) {
    Node<T> *q = p->childs[b];
    p->childs[b] = q->childs[!b];
    q->childs[!b] = p;

    p->factor = q->factor = 0;

    p = q;
}

template<class T>
void Tree<T>::rd(Node<T> *&p, bool b) {
    Node<T> *q = p->childs[b];
    Node<T> *r = q->childs[!b];

    p->childs[b] = r->childs[!b];
    q->childs[!b] = r->childs[b];

    r->childs[!b] = p;
    r->childs[b] = q;

    if (r->factor == 0)
        p->factor = q->factor = 0;
    else if (r->factor == 1) {
        r->childs[b]->factor = 0;
        r->childs[!b]->factor = -1;
    } else {
        r->childs[b]->factor = -1;
        r->childs[!b]->factor = 0;
    }

    p = r;
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
