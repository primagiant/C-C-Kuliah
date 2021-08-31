#include <iostream>
using namespace std;

class QNode{
	public:
		int value;
		QNode *next;
		QNode *prev;
		
		QNode(){
			next = prev = NULL;
		}
		
};

class Queue{
	QNode *front;
	QNode *rear;
	
	public:
		Queue(){
			front = rear = NULL;
		}
		
		void 	enqueue(int);
		int 	dequeue();
		
		void printAllElemets(){
			QNode *tmp = front;
			
			while (tmp!=NULL){
				cout << tmp->value << endl;
				tmp = tmp->next;
			}
		}
		
};
