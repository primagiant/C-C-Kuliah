#include <iostream>

#include "LinkedList.h"
using namespace std;

int main() {
    // Deklarasi LinkedList
    LinkedList list;

    // Menggunakan Method Pada Class yg sudah dibuat

    // Menambahkan Value dalam List
    list.addToHead(70);
    list.addToTail(5);
    list.addBefore(5, 10);
    list.addAfter(5, 15);
    list.addBefore(70, 65);
    list.addToTail(25);
    list.addBefore(25, 45);
    list.addBefore(10, 55);

    // Menampilkan Value dalam List sebelum dihapus
    list.printAllElements();

    // Menghapus Value dalam List
    list.deleteByValue(25);

    // Menampilkan Value dalam List setelah dihapus
    list.printAllElements();

    return 0;
}