// Membuat Class Node
class Node {
   public:
    int value;
    Node *next;

    // Construktor
    Node() {
        next = NULL;
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
        head = tail = NULL;
    };

    // Print Semua Elements dalam List
    void printAllElements();
    // Mencari suatu nilai dalam list
    void search(int);
    // Menambahkan Node Baru Dari Head
    void addToHead(int inputValue);
    // Menambahkan Node Baru Dari Tail
    void addToTail(int);
    // Menambahkan Node Baru Setelah Node Tertentu
    void addAfter(int, int);
    // Menambahkan Node Baru Sebelum Node Tertentu
    void addBefore(int, int);
    // Menghapus Dari Head
    void deleteFromHead();
    // Menghapus Dari Tail
    void deleteFromTail();
    // Menghapus dengan value tertentu
    void deleteByValue(int);
};
