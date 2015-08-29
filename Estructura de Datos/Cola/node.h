#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
    public:
        Node(T value) : value(value), next(0) {}
        ~Node() {}
        Node<T>* getNext();
        void setNext(Node *&node);
        T getValue();
    private:
        T value;
        Node<T> *next;
};

template<class T>
Node<T>* Node<T>::getNext() {
    return next;
}

template<class T>
void Node<T>::setNext(Node *&node) {
    next = node;
}

template<class T>
T Node<T>::getValue() {
    return value;
}

#endif
