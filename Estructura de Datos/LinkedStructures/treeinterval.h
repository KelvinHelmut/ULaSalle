#ifndef TREEINTERVAL
#define TREEINTERVAL

#include "treeredblack.h"
#include "nodeinterval.h"
#include <fstream>

template<class T>
class TreeInterval : public TreeRedBlack<Interval<T>*> {
private:
    bool add(Interval<T> *&value, Node<Interval<T>*> *&node);
    void dot(std::ostream &, Node<Interval<T>*> *&);
};

template<class T>
bool TreeInterval<T>::add(Interval<T> *&value, Node<Interval<T> *> *&node) {
    std::cout << "add interval" <<std::endl;
    if (!node) {
        node = new NodeInterval<T>(value);
        return true;
    }
    //if (*node->getValue() == value) return false;
    if (add(value, node->getLink(node->getValue()->getLow() < value->getLow()))) {
        //return true;
        node->getLink(node->getValue()->getLow() < value->getLow())->setLink(node, 2);
        this->case1(node->getLink(node->getValue()->getLow() < value->getLow()));
    }
    if (((NodeInterval<T>*) node)->getMax() < value->getHigh())
        ((NodeInterval<T>*) node)->setMax(value->getHigh());
    return false;
}

template<class T>
void TreeInterval<T>::dot(std::ostream &out, Node<Interval<T>*> *&node) {
    if (!node) return;
    NodeInterval<T> *me = (NodeInterval<T>*) node;
    NodeInterval<T> *child;

    out << "\"[" << node->getValue()->getLow() << "," << node->getValue()->getHigh() << "] (" << me->getMax() << ")\"";
    if (me->getColor() == NodeRB<T>::RED) out << "[color=red]";
    out << std::endl;

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

