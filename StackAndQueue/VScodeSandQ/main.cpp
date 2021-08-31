#include <iostream>

#include "Queue.h"
#include "Stack.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    // Percobaan Stack
    int s1, s2;
    cout << "Percobaan Stack" << endl;
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    // Print nilai stack setelah dipush 4x
    stack.printElements();

    s1 = stack.pop();
    s2 = stack.pop();

    // Print nilai stack setelah dipop 2x
    stack.printElements();

    // Kelaurkan hasil s1 = 20 + s2 = 15
    cout << s1 + s2 << endl;
    cout << endl;

    return 0;
}