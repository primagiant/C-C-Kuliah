#include <iostream>
using namespace std;

class SNode {
   public:
    int value;
    SNode *next;
    SNode *prev;

    SNode() {
        next = prev = NULL;
    }
};

class Stack {
   public:
    SNode *top;

    void printElements();
    void push(int);
    int pop();
};

void Stack::printElements() {
    SNode *tmp = top;
    while (tmp != NULL) {
        cout << tmp->value << " -> ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void Stack::push(int newStack) {
    SNode *tmp = new SNode();
    tmp->value = newStack;

    // Jika top kosong
    if (top == NULL) {
        top = tmp;
    }
    // jika stack berisi
    else {
        top->next = tmp;
        tmp->prev = top;
        top = tmp;
    }
}

int Stack::pop() {
    int nilaiPop;
    nilaiPop = top->value;
    top = top->prev;
    delete top->next;
    return nilaiPop;
}