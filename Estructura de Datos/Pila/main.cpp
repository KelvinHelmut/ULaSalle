
#include "stack.h"

#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(0);
    stack.push(6);

    while (!stack.isEmpty()) {
        cout << stack.getTop() << " ";
        stack.pop();
    }
    cout << endl;

    return 0;
}
