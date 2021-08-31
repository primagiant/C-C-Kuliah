#include <cstdio>

int main() {
	int x;
	printf("Masukkan Sebuah Bilangan : ");
	scanf("%d", &x);
	
	if( x % 2 == 0) {
		printf("Genap");
	} else {
		printf("Bukan Genap");
	}
}
