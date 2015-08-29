#ifndef STACK_H
#define STACK_H

#include "node.h"

template<class T>
class Stack {
    public:
        Stack() : top(0) {}
        ~Stack() {}
        void push(T value);
        void pop();
        bool isEmpty();
        T getTop();
    private:
        Node<T> *top;
};

template<class T>
inline void Stack<T>::push(T value){
    Node<T> *newNode = new Node<T>(value);
    newNode->setPrev(top);
    top = newNode;
}

template<class T>
inline void Stack<T>::pop(){
    if (isEmpty()) return;

    Node<T> *tmp = top;
    top = top->getPrev();
    delete tmp;
}

template<class T>
inline bool Stack<T>::isEmpty(){
    return top == 0;
}

template<class T>
inline T Stack<T>::getTop(){
    return top->getValue();
}

#endif
