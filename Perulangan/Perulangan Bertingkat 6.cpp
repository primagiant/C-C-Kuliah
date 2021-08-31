#include <cstdio>

int main() {
	
	for(int i = 10; i > 0; i--) {
		for(int j = 1; j <= 25; j++) {
			printf("%d ", i+=1);
		};
		printf("\n");
	}
	
	return 0;
}
