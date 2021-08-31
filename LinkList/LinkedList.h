#include <iostream>
using namespace std;

// Membuat Class Node
class Node {
   public:
    int value;
    Node *next;

    // Construktor
    Node() {
        next = nullptr;
    };
};

// Class untuk linklist
class LinkedList {
   protected:
    Node *head;
    Node *tail;

   public:
    // Constructor
    LinkedList() {
        head = tail = nullptr;
    };

    // Print Semua Elements dalam List
    void printAllElements() {
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
    void search(int target) {
        Node *tmp = new Node();
        tmp = head;

        while (tmp != NULL) {
            if (tmp->value == target) {
                cout << tmp->value << endl;
                break;
            }
            tmp = tmp->next;
        }
    };

    // Menambahkan Node Baru Dari Head
    void addToHead(int inputValue) {
        Node *tmp = new Node();
        tmp->value = inputValue;
        tmp->next = head;
        head = tmp;
        if (tail == NULL) {
            tail = head;
        }
    };

    // Menambahkan Node Baru Dari Tail
    void addToTail(int inputValue) {
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
    void addAfter(int target, int inputValue) {
        // Jika target adalah tail
        if (tail->value == target) {
            this->addToTail(inputValue);
            return;
        }
        // jika target bukan tail
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
    void addBefore(int target, int inputValue) {
        // Jika target adalah head
        if (head->value == target) {
            this->addToHead(inputValue);
            return;
        }
        // Jika target bukan Head
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
    void deleteFromHead() {
        Node *tmp = new Node();
        tmp = head;
        head = tmp->next;
        if (head == tail) {
            tail = tmp->next;
        }
        delete tmp;
    };

    // Menghapus Dari Tail
    void deleteFromTail() {
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
    void deleteByValue(int target) {
        // Kalau target sama dengan head atau tail
        if (head->value == target) {
            this->deleteFromHead();
        } else if (tail->value == target) {
            this->deleteFromTail();
        } else {
            // Kalau target bukan head atau tail
            Node *tmp = new Node();
            tmp = head;
            while (tmp != NULL) {
                if (tmp->next->value == target) {
                    Node *tmp2 = new Node();
                    tmp2 = tmp->next;
                    tmp->next = tmp2->next;
                    tmp2 = NULL;
                    // delete tmp2;
                    break;
                }
                tmp = tmp->next;
            }
        }
    };
};
