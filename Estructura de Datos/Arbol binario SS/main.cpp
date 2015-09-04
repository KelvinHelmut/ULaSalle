#include "tree.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Tree<int> tree;

    tree.add(5);
    tree.add(2);
    tree.add(6);
    tree.add(4);
    tree.add(7);
    tree.add(8);
    tree.add(1);
    tree.add(0);
    tree.add(9);

    cout << "Nodos: " << tree.count() << endl;
    cout << "Nodos Hoja: " << tree.countLeaf() << endl;
    cout << "Nodos Pares: " << tree.countEven() << endl;

    cout << "Padre de 8: " << tree.parent(8) << endl;
    cout << "Padre de 2: " << tree.parent(2) << endl;
    cout << "Hermano de 8: " << tree.brother(8) << endl;
    cout << "Hermano de 2: " << tree.brother(2) << endl;
    cout << "Tio de 8: " << tree.uncle(8) << endl;
    cout << "Tio de 2: " << tree.uncle(2) << endl;
    cout << "Tio de 0: " << tree.uncle(0) << endl;
    cout << "Abuelo de 8: " << tree.gparent(8) << endl;
    cout << "Abuelo de 2: " << tree.gparent(2) << endl;

    tree.print();

    return 0;
}
