#include <iostream>
#include "LinkedList.h"
using namespace std;

// Print Semua Elements dalam List
void LinkedList::printAllElements() {
    Node *tmp = head;
    while (tmp != NULL) {
        if (tmp == tail) {
            cout << tmp->value;
        } else {
            cout << tmp->value << " -> ";
        }
        tmp = tmp->next;
    }
    cout << endl;
};

// Mencari suatu nilai dalam list
void LinkedList::search(int target) {
	Node *tmp = new Node();
	tmp = head;
	
	while(tmp != NULL) {
		if(tmp->value == target) {
			cout << tmp->value << endl;
			break;
		}
		tmp = tmp->next;
	}
};

// Menambahkan Node Baru Dari Head
void LinkedList::addToHead(int inputValue) {
    Node *tmp = new Node();
    tmp->value = inputValue;
    tmp->next = head;
    head = tmp;
    if (tail == NULL) {
        tail = head;
    }
};

// Menambahkan Node Baru Dari Tail
void LinkedList::addToTail(int inputValue) {
    Node *tmp = new Node();
    tmp->value = inputValue;
    if (tail != NULL) {
        tail->next = tmp;
        tail = tmp;
    } else {
        tail = head = tmp;
    }
};

// Menambahkan Node Baru Setelah Node Tertentu
void LinkedList::addAfter(int target, int inputValue) {
    if (tail->value == target) {
        this->addToTail(inputValue);
        return;
    }
    Node *tmp = new Node();
    tmp = head;
    while (tmp != NULL) {
        if (tmp->value == target) {
            Node *newNode = new Node();
            newNode->value = inputValue;
            newNode->next = tmp->next;
            tmp->next = newNode;
            break;
        }
        tmp = tmp->next;
    }
};

// Menambahkan Node Baru Sebelum Node Tertentu
void LinkedList::addBefore(int target, int inputValue) {
    if (head->value == target) {
        this->addToHead(inputValue);
        return;
    }
    Node *tmp = new Node();
    tmp = head;
    while (tmp->next != NULL) {
        if (tmp->next->value == target) {
            Node *newNode = new Node();
            newNode->value = inputValue;
            newNode->next = tmp->next;
            tmp->next = newNode;
            break;
        }
        tmp = tmp->next;
    }
};

// Menghapus Dari Head
void LinkedList::deleteFromHead() {
    Node *tmp = new Node();
    tmp = head;
    head = tmp->next;
    if (head == tail) {
        tail = tmp->next;
    }
    delete tmp;
};

// Menghapus Dari Tail
void LinkedList::deleteFromTail() {
    Node *tmp = new Node();
    tmp = head;
    if (tmp != tail) {
        while (tmp->next != NULL) {
            if (tmp->next == tail) {
                tail = tmp;
                tmp->next = NULL;
                break;
            }
            tmp = tmp->next;
        }
    } else {
        head = tail = tmp->next;
        delete tmp;
    }
};

// Menghapus dengan value tertentu
void LinkedList::deleteByValue(int target) {
    // Kalau target sama dengan head atau tail
    if (head->value == target) {
        this->deleteFromHead();
        return;
    } else if (tail->value == target) {
        this->deleteFromTail();
        return;
    }
    // Kalau target bukan head atau tail
    Node *tmp = new Node();
    tmp = head;
    while (tmp != NULL) {
        if (tmp->next->value == target) {
            Node *tmp2 = new Node();
            tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;
            break;
        }
        tmp = tmp->next;
    }
}	

