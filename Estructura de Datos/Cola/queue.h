#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template<class T>
class Queue {
    public:
        Queue() : first(0), last(0) {}
        ~Queue() {}
        void enqueue(T value);
        void dequeue();
        bool isEmpty();
        T getFront();
    private:
        Node<T> *first, *last;
};

template<class T>
void Queue<T>::enqueue(T value) {
    Node<T> *newNode = new Node<T>(value);

    if (!first) {
        first = last = newNode;
    } else {
        last->setNext(newNode);
        last = newNode;
    }
}

template<class T>
void Queue<T>::dequeue() {
    if (!isEmpty()) {
        Node<T> *tmp = first;
        first = first->getNext();
        delete tmp;
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    return first == 0;
}

template<class T>
T Queue<T>::getFront() {
    return (!isEmpty()) ? first->getValue() : T();
}

#endif
