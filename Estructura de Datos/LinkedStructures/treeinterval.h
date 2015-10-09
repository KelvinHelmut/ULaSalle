#ifndef TREEINTERVAL
#define TREEINTERVAL

#include "tree.h"
#include "nodeinterval.h"
#include <fstream>

template<class T>
class TreeInterval : public Tree<Interval<T>*> {
public:
    TreeInterval() : root(0) {}
    void add(Interval<T>* value);
    void show(std::ostream &out);
    void dot(char* file);
private:
    bool add(Node<Interval<T>*> *&node, Interval<T> *&value);
    void show(std::ostream &out, Node<Interval<T>*> *&node);
    void dot(std::ostream &, Node<Interval<T>*> *&);

    Node<Interval<T>*> *root;
};

template<class T>
void TreeInterval<T>::add(Interval<T>* value) {
    add(root, value);
}

template<class T>
void TreeInterval<T>::show(std::ostream &out) {
    show(out, root);
}

template<class T>
bool TreeInterval<T>::add(Node<Interval<T>*> *&node, Interval<T> *&value) {
    if (!node) {
        node = new NodeInterval<T>(value);
        return true;
    }
    if (node->getValue()->getLow() == value->getLow() && node->getValue()->getHigh() == value->getHigh()) return false;
    if (add(node->getLink(node->getValue()->getLow() < value->getLow()), value)) {
        NodeInterval<T> *me = (NodeInterval<T>*) node;
        if (me->getMax() < value->getHigh())
            me->setMax(value->getHigh());
        return true;
    }
    return false;
}

template<class T>
void TreeInterval<T>::show(std::ostream &out, Node<Interval<T>*> *&node) {
    if (!node) return;
    out << "[" << node->getValue()->getLow() << ", " << node->getValue()->getHigh() << "]";

    if (node->getLink(0)) show(out, node->getLink(0));
    if (node->getLink(1)) show(out, node->getLink(1));
}

template<class T>
void TreeInterval<T>::dot(char* file) {
    std::ofstream out(file);
    out << "digraph G {" << std::endl;
    dot(out, root);
    out << "}";
}

template<class T>
void TreeInterval<T>::dot(std::ostream &out, Node<Interval<T>*> *&node) {
    if (!node) return;
    NodeInterval<T> *me = (NodeInterval<T>*) node;
    NodeInterval<T> *child;
    out << "\"[" << node->getValue()->getLow() << "," << node->getValue()->getHigh() << "] (" << me->getMax() << ")\"" << std::endl;
    if (node->getLink(0)) {
        child = (NodeInterval<T>*) node->getLink(0);
        out << "\"[" << node->getValue()->getLow() << "," << node->getValue()->getHigh() << "] (" << me->getMax() << ")\"" << "->"
            << "\"[" << child->getValue()->getLow() << "," << child->getValue()->getHigh() << "] (" << child->getMax() << ")\"" << std::endl;
    }
    if (node->getLink(1)) {
        child = (NodeInterval<T>*) node->getLink(1);
        out << "\"[" << node->getValue()->getLow() << "," << node->getValue()->getHigh() << "] (" << me->getMax() << ")\"" << "->"
            << "\"[" << child->getValue()->getLow() << "," << child->getValue()->getHigh() << "] (" << child->getMax() << ")\"" << std::endl;
    }
    dot(out, node->getLink(0));
    dot(out, node->getLink(1));
}

#endif // TREEINTERVAL

