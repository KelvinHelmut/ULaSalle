#include "list.h"

#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    List<float> list;

    list.addLast(2.5);
    list.addLast(4.3);
    list.addFront(5.6);
    list.deleteLast();

    return 0;
}
