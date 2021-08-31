#include <iostream>
#include "Queue.h"
using namespace std;

void Queue::enqueue(int inputValue){
	QNode *tmp = new QNode();
    tmp->value = inputValue;
    // jika antrean kosong
    if (front == NULL) {
        front = rear = tmp;
    }
    // jika ada antrean
    else {
        rear->next = tmp;
        tmp->prev = rear;
        rear = tmp;
    }
}

int Queue::dequeue(){
	int value;
    value = front->value;
    // jika hanya ada satu antrean
    if (front == rear) {
        delete front;
    }
    // jika ada lebih dari 1 antrean
    else {
        front = front->next;
        delete front->prev;
    }
    return value; 
	// keluaran berupa nilai elemen pertama(front) yang di-dequeue
}
