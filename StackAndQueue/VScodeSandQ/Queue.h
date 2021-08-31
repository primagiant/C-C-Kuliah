#include <iostream>
using namespace std;

class QNode {
   public:
    int value;
    QNode *next;
    QNode *prev;

    QNode() {
        next = prev = NULL;
    }
};

class Queue {
   public:
    QNode *front;
    QNode *rear;

    Queue() {
        front = rear = NULL;
    }

    void printElements();
    void enqueue(int);
    int dequeue();
};

void Queue::printElements() {
    QNode *tmp = front;
    while (tmp != NULL) {
        cout << tmp->value << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}

void Queue::enqueue(int enqueuValue) {
    QNode *tmp = new QNode();
    tmp->value = enqueuValue;
    // jika Antrean kosong
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

int Queue::dequeue() {
    int dequeueValue;
    dequeueValue = front->value;
    // jika hanya ada satu antrean
    if (front == rear) {
        delete front;
    }
    // jika ada lebih dari 1 antrean
    else {
        front = front->next;
        delete front->prev;
    }
    return dequeueValue;
}
