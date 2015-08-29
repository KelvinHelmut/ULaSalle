#include "queue.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(void) {
    Queue<std::string> queue;

    queue.enqueue("Alice");
    queue.enqueue("Gabrielle");
    queue.enqueue("Jessy");
    queue.enqueue("James");
    queue.enqueue("Juan");

    while (!queue.isEmpty()) {
        cout << queue.getFront() << " ";
        queue.dequeue();
    }
    cout << endl;

    return 0;
}
