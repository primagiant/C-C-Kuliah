#include <iostream>
#include "LinkedList.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
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
    list.deleteByValue(10);

    // Menampilkan Value dalam List setelah dihapus
    list.printAllElements();

	// agar .exe bisa dibuka
	cin.get();
    return 0;
}
