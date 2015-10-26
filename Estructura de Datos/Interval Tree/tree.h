#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <fstream>
#include <iostream>

template<class T>
class Tree {
    public:
        Tree() : root(0) {}
        void insert(T min, T max) { if (insert(min, max, root)) case1(root); }
        void dot(char * file) {
            std::ofstream out(file);
            out << "digraph G {" << std::endl;
            dot(out, root);
            out << "}";
        }
    private:
        bool insert(T &, T &, Node<T> *& root);
        void case1(Node<T> * p);
        void case2(Node<T> * p);
        void case3(Node<T> * p);
        void case4(Node<T> * p);
        void case5(Node<T> * p);

        void rotation(Node<T> * node, bool b);

        void dot(std::ostream &, Node<T> *&);

        Node<T> * root;
};

template<class T>
bool Tree<T>::insert(T & min, T & max, Node<T> *& root) {
    if (!root) {
        root = new Node<T>(min, max);
        return true;
    }
    if (root->values[0] == min && root->values[1] == max) return false;
    if (insert(min, max, root->links[root->values[0] < min])) {
        root->links[root->values[0] < min]->links[2] = root;
        case1(root->links[root->values[0] < min]);
    }
    if (root && root->values[2] < max) root->values[2] = max;
    return false;
}

template<class T>
void Tree<T>::case1(Node<T> * p) {
    if (!p->links[2])
        p->red = 0;
    else 
        case2(p);
}

template<class T>
void Tree<T>::case2(Node<T> * p) {
    if (!p->links[2]->red) return;
    case3(p);
}

template<class T>
void Tree<T>::case3(Node<T> * p) {
    Node<T> * g = p->links[2]->links[2];
    Node<T> * u = g->links[g->values[0] > p->values[0]];

    if (u && u->red) {
        p->links[2]->red = 0;
        u->red = 0;
        g->red = 1;
        case1(g);
        return;
    }
    case4(p);
}

template<class T>
void Tree<T>::case4(Node<T> * p) {
    Node<T> * g = p->links[2]->links[2];

    if (p == p->links[2]->links[1] && p->links[2] == g->links[0]) {
        rotation(p->links[2], 1);
        p = p->links[0];
    } else if (p == p->links[2]->links[0] && p->links[2] == g->links[1]) {
        rotation(p->links[2], 0);
        p = p->links[1];
    }
    case5(p);
}

template<class T>
void Tree<T>::case5(Node<T> * p) {
    Node<T> * g = p->links[2]->links[2];

    p->links[2]->red = 0;
    g->red = 1;

    if (p == p->links[2]->links[0] && p->links[2] == g->links[0])
        rotation(p->links[2]->links[2], 0);
    else
        rotation(p->links[2]->links[2], 1);
}

template<class T>
void Tree<T>::rotation(Node<T> * p, bool b) {
    Node<T> * q = p->links[b];

    p->links[b] = q->links[!b];
    q->links[!b] = p;

    q->links[2] = p->links[2];
    p->links[2] = q;

    if (!q->links[2])
        root = q;
    else 
        q->links[2]->links[q->links[2]->values[0] < q->values[0]] = q;
}

template<class T>
void Tree<T>::dot(std::ostream &out, Node<T> *& root) {
    if (!root) return;
    out << root;
    if (root->red) out << "[color=red]";
    out << std::endl;
    if (root->links[0]) out << root << "->" << root->links[0] << std::endl;
    if (root->links[1]) out << root << "->" << root->links[1] << std::endl;
    dot(out, root->links[0]);
    dot(out, root->links[1]);
}

#endif
