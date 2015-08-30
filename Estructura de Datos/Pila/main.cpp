
#include "stack.h"

#include <iostream>
#include <string.h>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istringstream;

typedef float number;

template<class T>
bool isNumber(string str, T &number);

int getOperation(string str);

template<class T>
T suma(T a, T b);

template<class T>
T resta(T a, T b);

template<class T>
T multiplica(T a, T b);

template<class T>
T divide(T a, T b);

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


    Stack<number> numbers;
    number n, a, b;
    number (*operation[])(number, number) = {suma, resta, multiplica, divide};
    std::string str;
    char *val;
    int op;
    
    cout << endl << "Expresión algebraíca posfija: " ;
    getline(cin, str);
    val = strtok((char*)str.c_str(), " ");
    while (val != NULL) {
        if (isNumber<number>(val, n)) 
            numbers.push(n);
        else {
            op = getOperation(val);
            if (op == -1) {
                cout << "Operador: " << val << " es inválido" << endl;
                return -1;
            }

            b = numbers.getTop();
            numbers.pop();
            a = numbers.getTop();
            numbers.pop();

            numbers.push(operation[op](a, b));
        }
        val = strtok(NULL, " ");
    }

    cout << "El resultado es: " << numbers.getTop() << endl;

    return 0;
}

template<class T>
bool isNumber(string str, T &number) {
    istringstream ss(str);
    return ss >> number;
}

int getOperation(string str) {
    string operations[4] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++) 
        if (str == operations[i]) return i;

    return -1;
}

template<class T>
T suma(T a, T b) {
    return a + b;
}

template<class T>
T resta(T a, T b) {
    return a - b;
}

template<class T>
T multiplica(T a, T b) {
    return a * b;
}

template<class T>
T divide(T a, T b) {
    return (b) ? a / b : 0;
}
