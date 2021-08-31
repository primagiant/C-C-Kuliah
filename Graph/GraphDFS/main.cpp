#include <iostream>
using namespace std;

#define size 9
//int 	size;
int 	stack[size];
int 	top;
bool	isVisited[size]; // true jika vertex sudah dikunjungi, false jika vertex belum dikunjungi

int findNextVertex(int graph[size][size], int currVertex){ // currVertex adalah vertex yang sedang dikunjungi
	
	for (int i=0; i<size; i++){
		if (graph[currVertex][i] !=0 && currVertex!=i && !isVisited[i]){
			return i;
		}
	}
	return -1;
}

void DFS(int graph[size][size], int start){
	
	top 	 		 = 0;
	stack[0] 		 = start;
	isVisited[start] = true;
	
	while (top > -1){ // jika stack tidak kosong
		
		int nextVertex = findNextVertex(graph, stack[top]);
		
		if (nextVertex != -1){ // jika ada vertex yang belum dikunjungi
			// push nexVertex ke stack
			top++;
			stack[top] 			  = nextVertex;
			isVisited[nextVertex] = true;
		}else{
			// pop elemen dari stack
			cout << (char)(stack[top]+65) << endl;
			top--;
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	top = -1; // stack kosong
	
	for (int i=0; i<size; i++){
		isVisited[i] = false;
		stack[i]	 = -1;
	}
	
	int graph[size][size] = {
		//		 A 	B  C  D  E  F  G  H  I
		/*A*/	{0, 1, 1, 1, 0, 0, 0, 0, 0},
		/*B*/	{1, 0, 1, 0, 1, 0, 0, 0, 0},
		/*C*/	{1, 1, 0, 1, 0, 1, 1, 0, 0},
		/*D*/	{1, 0, 1, 0, 0, 0, 1, 0, 0},
		/*E*/	{0, 1, 0, 0, 0, 0, 0, 0, 0},
		/*F*/	{0, 0, 1, 0, 0, 0, 0, 0, 1},
		/*G*/	{0, 0, 1, 1, 0, 0, 0, 1, 0},
		/*H*/	{0, 0, 0, 0, 0, 0, 1, 0, 0},
		/*I*/	{0, 0, 0, 0, 0, 1, 0, 0, 0},
	};
	
	DFS(graph, 0);
	
	return 0;
}
