class Node
{
public:
    int value;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void addToHead(int);
    void addToTail(int);
    void addAfter(int, int);
    void addBefore(int, int);

    void printAllElement();
    void search();

    void deleteHead();
    void deleteTail();
    void deleteNode();
};