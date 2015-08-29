#include "list.h"

int main(void) {
    List list;
    
    list.add(34);
    list.add(64);
    list.add(2);
    list.add(18);
    list.add(199);

    list.print();

    list.reverse();

    list.print();

    return 0;
}
