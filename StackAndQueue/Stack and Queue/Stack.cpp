#include <iostream>
#include "Stack.h"
using namespace std;


void Stack::push(int inputValue){
	SNode *tmp = new SNode();
    tmp->value = inputValue;

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

int Stack::pop(){
	int value;
    value = top->value;
    top = top->prev;
    delete top->next;
    return value;// keluaran berupa nilai elemen terakhir (top) yang di-pop
}
