#ifndef NODE_H
#define NODE_H

class Node {
    public:
        Node(int value) : value(value), next(0) {}
        ~Node() {}
        Node*& getNext();
        void setNext(Node *node);
        int getValue();
    private:
        int value;
        Node *next;
};

#endif
