#include "node.h"

Node*& Node::getNext() {
    return next;
}

void Node::setNext(Node *node) {
    next = node;
}

int Node::getValue() {
    return value;
}

