#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::addToHead(int value) {
    Node *tmp;
    tmp->value = value;
    tmp->next = head;
    head = tmp;
    
    if (tail == NULL) {
        tail = head;
    }
}

void LinkedList::printAllElement() {
    Node *tmp = head;
    while (tmp != NULL) {
        cout << tmp->value << "->";
        tmp = tmp->next;
    }
}

