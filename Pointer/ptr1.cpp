#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

main() {
	
	int n1 = 2, n2 = 5;
	
	swap(&n1, &n2);
	
}
