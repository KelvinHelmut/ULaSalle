#ifndef NODERB
#define NODERB

#include "node.h"

template<class T>
class NodeRB : public Node<T> {
public:
    enum Color {
        RED, BLACK
    };

    NodeRB();
    NodeRB(T);
    T getValue();
    Node<T>*& getLink(int);
    void setLink(Node<T>*, int);
    Color getColor() { return color; }
    void setColor(Color);

    bool operator < (Node<T> &);
    bool operator <= (Node<T> &);
    bool operator > (Node<T> &);
    bool operator >= (Node<T> &);
    bool operator == (Node<T> &);

protected:
    T value;

private:
    Color color;
    Node<T> *links[3];
};

template<class T>
NodeRB<T>::NodeRB() : color(NodeRB::RED) {
    links[0] = links[1] = links[2] = 0;
}

template<class T>
NodeRB<T>::NodeRB(T value) : value(value), color(NodeRB::RED) {
    links[0] = links[1] = links[2] = 0;
}

template<class T>
T NodeRB<T>::getValue() {
    return value;
}

template<class T>
Node<T>*& NodeRB<T>::getLink(int i) {
    return links[i];
}

template<class T>
void NodeRB<T>::setLink(Node<T> *node, int i) {
    links[i] = node;
}

template<class T>
void NodeRB<T>::setColor(Color color) {
    this->color = color;
}

template<class T>
bool NodeRB<T>::operator < (Node<T> &node) {
    return getValue() < node.getValue();
}

template<class T>
bool NodeRB<T>::operator <= (Node<T> &node) {
    return this->operator <(node) || this->operator ==(node);
}

template<class T>
bool NodeRB<T>::operator > (Node<T> &node) {
    return !this->operator <=(node);
}

template<class T>
bool NodeRB<T>::operator >= (Node<T> &node) {
    return !this->operator <(node);
}

template<class T>
bool NodeRB<T>::operator == (Node<T> &node) {
    return getValue() == node.getValue();
}

#endif // NODERB

