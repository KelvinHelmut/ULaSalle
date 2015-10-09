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
        void insert(T value) { insert(value, root); }
        void printDot(char*);
    private:
        bool insert(T value, Node<T> *&node);
        void rs(Node<T> *&p, bool);
        void rd(Node<T> *&p, bool);
        void caso1(Node<T> *&p);
        void caso2(Node<T> *&p);
        void caso3(Node<T> *&p);
        void caso4(Node<T> *&p);
        void caso5(Node<T> *&p);
        void printDot(Node<T>*, std::ostream&);
        Node<T> *root;
};

template<class T>
void Tree<T>::rs(Node<T> *&p, bool b) {
    Node<T> *q = p->links[b];
    p->links[b] = q->links[!b];
    q->links[!b] = p;

    if (p == root) {
        root = q;
        q->links[2] = 0;
    } else {
        p->links[2]->links[p->links[2]->value < p->value] = q;
        q->links[2] = p->links[2];
    }

    p->links[2] = q;

    /* p = q; */
}

template<class T>
void Tree<T>::rd(Node<T> *&p, bool b) {
    Node<T> *q = p->links[b];
    Node<T> *r = q->links[!b];

    p->links[b] = r->links[!b];
    q->links[!b] = r->links[b];

    r->links[!b] = p;
    r->links[b] = q;

    if (p == root) {
        root = r;
        r->links[2] = 0;
    } else {
        p->links[2]->links[p->links[2]->value < p->value] = r;
        r->links[2] = p->links[2];
    }

    p->links[2] = r;

    /* p = r; */
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
    std::cout << node->links[2] << ", ";
    out << node->value;
    if (node->color == node->RED)
        out << " [color=red]";
    else 
        out << " [color=black]";
    if (node->links[0])
        out << node->value << "->" << node->links[0]->value << endl;
    if (node->links[1])
        out << node->value << "->" << node->links[1]->value << endl;
    printDot(node->links[0], out);
    printDot(node->links[1], out);
}

template<class T>
bool Tree<T>::insert(T value, Node<T> *&node) {
    if (!node) {
        node = new Node<T>(value);
        if (node == root) {
            caso1(node);
        }
        return true;
    }
    else {
        if (insert(value, node->links[node->value < value])) {
            node->links[node->value < value]->links[2] = node;
            caso1(node->links[node->value < value]);
        }
        return false;
    }
}

template<class T>
void Tree<T>::caso1(Node<T> *&p) {
    if (!p->links[2])
        p->color = p->BLACK;
    else 
        caso2(p);
}

template<class T>
void Tree<T>::caso2(Node<T> *&p) {
    if (p->links[2]->color == p->BLACK) return;
    caso3(p);
}

template<class T>
void Tree<T>::caso3(Node<T> *&p) {
    Node<T> *g = p->links[2]->links[2];
    Node<T> *q = g->links[g->value > p->value];

    if (p->links[2]->color == p->RED && q && q->color == p->RED) {
        p->links[2]->color = q->color = p->BLACK;
        g->color = p->RED;
        caso1(g);
        return;
    }
    caso4(p);
}

template<class T>
void Tree<T>::caso4(Node<T> *&p) {
    Node<T> *g = p->links[2]->links[2];
    Node<T> *q = g->links[g->value > p->value];

    if (p->links[2]->color == p->RED && q && q->color == p->BLACK) {
        if (p == p->links[2]->links[1] && p->links[2] == g->links[0]) {
            rd(g, 0);
            p = p->links[0];
        } else if (p == p->links[2]->links[0] && p->links[2] == g->links[1]) {
            rd(g, 1);
            p = p->links[1];
        }
    }
    caso5(p);
}

template<class T>
void Tree<T>::caso5(Node<T> *&p) {
    Node<T> *g = p->links[2]->links[2];
    Node<T> *q = g->links[g->value > p->value];

    if (p->links[2]->color == p->RED) {
        if (p == p->links[2]->links[0] && p->links[2] == g->links[0]) {
            p->links[2]->color = p->BLACK;
            g->color = p->RED;
            rs(g, 0);
        } else if (p == p->links[2]->links[1] && p->links[2] == g->links[1]) {
            p->links[2]->color = p->BLACK;
            g->color = p->RED;
            rs(g, 1);
        }
    }
}

#endif
