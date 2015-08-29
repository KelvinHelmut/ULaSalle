#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
    public:
        Node(T value) : value(value), next(0), prev(0) {}
        ~Node() {}
        Node<T>* getNext();
        void setNext(Node *next);
        Node<T>* getPrev();
        void setPrev(Node *prev);
        T getValue();
    private:
        T value;
        Node<T> *next, *prev;
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
Node<T>* Node<T>::getPrev() {
    return prev;
}

template<class T>
void Node<T>::setPrev(Node *prev) {
    this->prev = prev;
}

template<class T>
T Node<T>::getValue() {
    return value;
}

#endif
