#include <iostream>
using namespace std;

#define size 9
//int 	size;
int 	queue[size];
int 	front, back;
bool	isVisited[size]; // true jika vertex sudah dikunjungi, false jika vertex belum dikunjungi

int findNextVertex(int graph[size][size], int currVertex){ // currVertex adalah vertex yang sedang dikunjungi
	
	for (int i=0; i<size; i++){
		if (graph[currVertex][i] !=0 && currVertex!=i && !isVisited[i]){
			return i;
		}
	}
	return -1;
}

void BFS(int graph[size][size], int start){
	
	// implementasi bagaimana starting poin
	front 		= 0; 
	back		= 0;
	queue[0] 	= start;
	isVisited[start] = true;

	
	// bagaimana proses BFS
	while (front != back+1 || (back == 0 && front == 0)){ // jika queue tidak kosong// kondisinya mungkin berubah
		int nextVertex = findNextVertex(graph, queue[front]);
		
		if(nextVertex != -1){
			// enqueue kedalam queue
			back++;
			queue[back] 			= nextVertex;
			isVisited[nextVertex] 	= true;
		} else {
			// dequeue dari queue
			cout << char(queue[front]+65)<< endl;
			front++;
		}
	}
}

int main(int argc, char** argv) {
	
	// bagaimana inisialisasinya
	front 		= 0;
	back 		= 0;
	for(int i = 0; i < size; i++) {
		queue[i] 		= 0;
		isVisited[i]	= false;
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
	
	BFS(graph, 0);
	
	return 0;
}
