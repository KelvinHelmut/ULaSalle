#include "tree.h"

int main(void) {
    Tree<int> tree;

    for (int i = 0; i < 6; i++)
        tree.insert(i);

    tree.printDot("avl.dot");
    return 0;
}
