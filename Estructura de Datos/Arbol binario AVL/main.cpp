#include "tree.h"

int main(void) {
    Tree<int> tree;

    for (int i = 0; i < 100; i++)
        tree.add(i);

    tree.printDot("avl.dot");
    return 0;
}
