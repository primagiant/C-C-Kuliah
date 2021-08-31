#include <iostream>
using namespace std;

class SNode{
	public:
		int value;
		SNode *next;
		SNode *prev;
		
		SNode(){
			next = prev = NULL;
		}
		
};

class Stack{
	SNode *top;
	
	public:
		Stack(){
			top = NULL;
		}
		
		void 	push(int);
		int 	pop();
		
		void printAllElemets(){
			SNode *tmp = top;
			
			while (tmp!=NULL){
				cout << tmp->value << endl;
				tmp = tmp->prev;
			}
		}
};
