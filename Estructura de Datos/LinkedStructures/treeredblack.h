#ifndef TREEREDBLACK
#define TREEREDBLACK

#include "tree.h"
#include "noderb.h"

#include <fstream>

template<class T>
class TreeRedBlack : public Tree<T> {
public:
    TreeRedBlack() : root(0) {}
    void add(T);
    void show(std::ostream&) {}
    void dot(char *file);

protected:
    void case1(Node<T> *&node);

private:
    void case2(Node<T> *&node);
    void case3(Node<T> *&node);
    void case4(Node<T> *&node);
    void case5(Node<T> *&node);
    void rotation(Node<T> *&node, bool b);

    virtual bool add(T&, Node<T> *&);
    virtual void dot(std::ostream &out, Node<T> *&node);

    Node<T> *root;
};

template<class T>
void TreeRedBlack<T>::add(T value) {
    if (add(value, root)) case1(root);
}

template<class T>
void TreeRedBlack<T>::dot(char *file) {
    std::ofstream out(file);
    out << "digraph G {" << std::endl;
    dot(out, root);
    out << "}";
}

template<class T>
bool TreeRedBlack<T>::add(T &value, Node<T> *&node) {
    std::cout << "add rb" << std::endl;
    if (!node) {
        node = new NodeRB<T>(value);
        return true;
    }
    if (node->getValue() == value) return false;
    if (add(value, node->getLink(node->getValue() < value))) {
        node->getLink(node->getValue() < value)->setLink(node, 2);
        case1(node->getLink(node->getValue() < value));
    }
    return false;
}

template<class T>
void TreeRedBlack<T>::dot(std::ostream &out, Node<T> *&node) {
    if (!node) return;
    NodeRB<T> *me = (NodeRB<T>*) node;
    out << node->getValue();
    if (me->getColor() == NodeRB<T>::RED) out << "[color=red]";
    out << std::endl;
    if (node->getLink(0)) out << node->getValue() << "->" << node->getLink(0)->getValue() << std::endl;
    if (node->getLink(1)) out << node->getValue() << "->" << node->getLink(1)->getValue() << std::endl;
    dot(out, node->getLink(0));
    dot(out, node->getLink(1));
}

template<class T>
void TreeRedBlack<T>::case1(Node<T> *&node) {
    if (!node->getLink(2))
        ((NodeRB<T>*) node)->setColor(NodeRB<T>::BLACK);
    else
        case2(node);
}

template<class T>
void TreeRedBlack<T>::case2(Node<T> *&node) {
    if (((NodeRB<T>*) node->getLink(2))->getColor() == NodeRB<T>::BLACK) return;
    case3(node);
}

template<class T>
void TreeRedBlack<T>::case3(Node<T> *&node) {
    Node<T> *gparent = node->getLink(2)->getLink(2);
    Node<T> *uncle = gparent->getLink(gparent->getValue() > node->getValue());

    if (uncle && ((NodeRB<T>*) uncle)->getColor() == NodeRB<T>::RED) {
        ((NodeRB<T>*) node->getLink(2))->setColor(NodeRB<T>::BLACK);
        ((NodeRB<T>*) uncle)->setColor(NodeRB<T>::BLACK);
        ((NodeRB<T>*) gparent)->setColor(NodeRB<T>::RED);
        case1(node->getLink(2)->getLink(2));
        return;
    }
    case4(node);
}

template<class T>
void TreeRedBlack<T>::case4(Node<T> *&node) {
    Node<T> *gparent = node->getLink(2)->getLink(2);
    Node<T> **tmp = &node;

    if (node == node->getLink(2)->getLink(1) && node->getLink(2) == gparent->getLink(0)) {
        rotation(node->getLink(2), 1);
        tmp = &(gparent->getLink(0)->getLink(0));
    } else if (node == node->getLink(2)->getLink(0) && node->getLink(2) == gparent->getLink(1)) {
        rotation(node->getLink(2), 0);
        tmp = &(gparent->getLink(1)->getLink(1));
    }
    case5(*tmp);
}

template<class T>
void TreeRedBlack<T>::case5(Node<T> *&node) {
    Node<T> *gparent = node->getLink(2)->getLink(2);

    ((NodeRB<T>*) node->getLink(2))->setColor(NodeRB<T>::BLACK);
    ((NodeRB<T>*) gparent)->setColor(NodeRB<T>::RED);

    if (node == node->getLink(2)->getLink(0) && node->getLink(2) == gparent->getLink(0)) {
        rotation(node->getLink(2)->getLink(2), 0);
    } else {
        rotation(node->getLink(2)->getLink(2), 1);
    }
}

template<class T>
void TreeRedBlack<T>::rotation(Node<T> *&node, bool b) {
    Node<T> *child = node->getLink(b);
    Node<T> *parent = node->getLink(2);

    node->setLink(child->getLink(!b), b);
    child->setLink(node, !b);

    node->setLink(child, 2);
    child->setLink(parent, 2);

    if (parent)
        parent->setLink(child, parent->getValue() < child->getValue());
    else
        root = child;
}

#endif // TREEREDBLACK

