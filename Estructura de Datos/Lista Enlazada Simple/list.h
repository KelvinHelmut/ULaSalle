#ifndef LIST_H
#define LIST_H

#include "node.h"

template<class T>
class List {
    public:
        List() : head(0), last(0) {}
        ~List() {}
        void addLast(T value);
        void addFront(T value);
        void deleteLast();
        void deleteFront();
        bool find(T value, Node<T> *&node);
    private:
        Node<T> *head, *last;
};

template<class T>
void List<T>::addLast(T value) {
    Node<T> *newNode = new Node<T>(value);

    if (!head) {
        head = last = newNode;
    } else {
        last->setNext(newNode);
        last = newNode;
    }
}

template<class T>
void List<T>::addFront(T value) {
    Node<T> *newNode = new Node<T>(value);

    if (!head) {
        head = last = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
}

template<class T>
void List<T>::deleteLast() {
    if (head) {
        delete last;
        last = head;
        while (last->getNext())
            last = last->getNext();
    }
}

template<class T>
void List<T>::deleteFront() {
    if (head) {
        Node<T> *tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

template<class T>
bool List<T>::find(T value, Node<T> *&node) {
    Node<T> *tmp = head;

    while (tmp) {
        if (tmp->getValue() == value)
            return true;
        tmp = tmp->getNext();
    }
    
    return false;
}

#endif
