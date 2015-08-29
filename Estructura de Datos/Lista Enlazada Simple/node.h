#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
    public:
        Node(T value) : value(value), next(0) {}
        ~Node() {}
        Node<T>* getNext();
        void setNext(Node *next);
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
void Node<T>::setNext(Node *next) {
    this->next = next;
}

template<class T>
T Node<T>::getValue() {
    return value;
}

#endif
