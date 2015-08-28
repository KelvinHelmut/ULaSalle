#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
    public:
        Node(T value) : value(value), prev(0) {}
        ~Node() {}
        Node<T>* getPrev();
        void setPrev(Node *&prev);
        T getValue();
    private:
        T value;
        Node<T> *prev;
};

template<class T>
inline Node<T>* Node<T>::getPrev() {
    return prev;
}

template<class T>
inline void Node<T>::setPrev(Node *&prev) {
    this->prev = prev;
}

template<class T>
inline T Node<T>::getValue() {
    return value;
}

#endif
