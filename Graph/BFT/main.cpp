#include <iostream>
using namespace std;

#define size 9
int queue[size];
int front;
int rear;
bool isVisited[size];  //true jika vertex sudah dikunjungi, false jika vertex belum dikunjungi

int findNextVertex(int graph[size][size], int currVertex)  // currvertex
{
    for (int i = 0; i < size; i++) {
        if (graph[currVertex][i] != 0 && currVertex != i && !isVisited[i]) {
            return i;
        }
    }
    return -1;
}

void BFS(int graph[size][size], int start) {
    front = 0;
    rear = 0;
    queue[0] = start;
    isVisited[start] = true;

    while (front != rear || rear == 0)  //jika queue tidak kosong
    {
        int nextVertex = findNextVertex(graph, front);

        if (nextVertex == -1) {
            // enqueue vertex ke queue
            rear++;
            queue[rear] = nextVertex;
            isVisited[nextVertex] = true;
        } else {
            // dequeue vertex ke queue
            cout << queue[front] << endl;
            front++;
        }
    }
}

int main(int argc, char** argv) {
    front = 0;  //stack kosong
    rear = 0;   //stack kosong
    for (int i = 0; i < size; i++) {
        isVisited[i] = false;
        queue[i] = 0;
    }

    int graph[size][size] = {
        //       A  B  C  D  E  F  G  H   I
        /* A */ {0, 1, 1, 1, 0, 0, 0, 0, 0},
        /* B */ {1, 0, 1, 0, 1, 0, 0, 0, 0},
        /* C */ {1, 1, 0, 1, 0, 1, 1, 0, 0},
        /* D */ {1, 0, 1, 0, 0, 0, 1, 0, 0},
        /* E */ {0, 1, 0, 0, 0, 0, 0, 0, 0},
        /* F */ {0, 0, 1, 0, 0, 0, 0, 0, 1},
        /* G */ {0, 0, 1, 1, 0, 0, 0, 1, 0},
        /* H */ {0, 0, 0, 0, 0, 0, 1, 0, 0},
        /* I */ {0, 0, 0, 0, 0, 1, 0, 0, 0},
    };

    BFS(graph, 0);

    return 0;
}