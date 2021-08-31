#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Stack stack;
	cout << "Percobaan Stack\n";
	int s1, s2;
	/*---- panggil method push dan pop di sini ----*/
	stack.push(5);
	stack.push(10);
	stack.push(15);
	stack.push(20);
	
	cout << "Isi Stack Setelah Di Push 4x :" << endl;
	stack.printAllElemets();
	
	s1 = stack.pop();
	s2 = stack.pop();
	
	cout << "\nIsi Stack Setelah Di Pop 2x :" << endl;
	stack.printAllElemets();
	
	cout << "\nJumlah nilai yang keluar dari stack\n"
		 << s1 << " + " << s2 << " = "<< s1 + s2 << endl;
	
	Queue queue;
	cout << "-----------------------------------\n";
	cout << "\n\nPercobaan Queue\n";
	int q1, q2;
	/*---- panggil method enqueue dan dequeue di sini ----*/
	queue.enqueue(5);
	queue.enqueue(10);
	queue.enqueue(15);
	queue.enqueue(20);

	cout << "Isi Queue Setelah Di enqueue 4x :" << endl;
	queue.printAllElemets();
	
	q1 = queue.dequeue();
	q2 = queue.dequeue();
	
	cout << "\nIsi Queue Setelah Di dequeue 2x :" << endl;
	queue.printAllElemets();
	
	cout << "\nJumlah nilai yang keluar dari stack\n"
		 << q1 << " + " << q2 << " = "<< q1 + q2 << endl;
		 
	return 0;
}
