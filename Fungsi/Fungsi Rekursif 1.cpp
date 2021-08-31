#include <cstdio>
#include <cstdlib>

int faktorial(int a) {
	if(a == 1) {
		return 1;
	} else {
		return a*faktorial(a-1);
	}
}

int main() {
	int test,
		nilai;
		
	nilai = 5;
	
	test = faktorial(nilai);
	printf("%d", test);
	
	return 0;
}
