#include "tree.h"

int main(void) {
    Tree<int> tree;
    tree.insert(1,2);
    tree.insert(2,3);
    tree.insert(3,4);
    tree.insert(4,5);
    tree.insert(5,6);
    tree.insert(6,7);
    tree.insert(7,8);
    tree.insert(8,9);
    tree.insert(9,10);
    tree.insert(10,11);
    tree.insert(11,12);
    tree.insert(12,14);
    tree.insert(13,15);
    tree.dot("midot.dot");
    /* system("dot -Tpng midot.dot -o dot.png"); */
    return 0;
}
