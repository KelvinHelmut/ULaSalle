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

int List::max() {
    Node *node = head;

    while (node) {
        if (!node->getNext())
            return node->getValue();
        node = node->getNext();
    }

    return 0;
}

int List::min() {
    return head->getValue();
}

List* List::join(List *&list) {
    List *newList = new List();
    Node *node = head;
    
    while (node) {
        newList->add(node->getValue());
        node = node->getNext();
    }

    node = list->head;
    while (node) {
        newList->add(node->getValue());
        node = node->getNext();
    }

    return newList;
}

List* List::intersection(List *&list) {
    List *newList = new List();
    Node *node = head;
    Node **tmp = 0;

    while (node) {
        if (list->find(node->getValue(), tmp))
            newList->add(node->getValue());
        node = node->getNext();
    }

    return newList;
}

