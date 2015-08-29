#include "list.h"

void List::add(int value) {
    Node **tmp;

    if (find(value, tmp))
        return;

    Node *newNode = new Node(value);
    newNode->setNext(*tmp);
    *tmp = newNode;
}

bool List::find(int value, Node **&node) {
    node = &head;

    while (*node) {
        if ((*node)->getValue() == value)
            return true;
        if ((*node)->getValue() > value)
            return false;
        node = &((*node)->getNext());
    }

    return false;
}

void List::print() {
    Node *node = head;

    while (node) {
        cout << node->getValue() << " ";
        node = node->getNext();
    }
    cout << endl;
}

void List::reverse() {
    if (!head) return;

    Node *node = head;
    Node *next = head->getNext();
    Node *tmp = 0;

    head->setNext(0);

    while (next) {
        tmp = next->getNext();
        next->setNext(node);
        node = next;
        next = tmp;
    }

    head = node;
}

