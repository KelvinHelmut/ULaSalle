
#include "stack.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(void) {
    Stack<std::string> stack;
    
    stack.push("Gabrielle");
    stack.push("Luna");
    stack.push("Juan");
    stack.push("James");
    stack.push("Jessy");

    while (!stack.isEmpty()) {
        cout << stack.getTop() << " ";
        stack.pop();
    }
    cout << endl;

    return 0;
}
