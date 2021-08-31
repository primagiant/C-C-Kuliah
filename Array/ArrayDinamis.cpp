#include <cstdio>

int main() {
	// Memasukkan Banyaknya data yang akan dinputkan
	int n;
	printf("Berapa data yang ingin anda Masukkan ? : ");
	scanf("%d", &n);
	
	// Membuat array dengan nama data
	printf("\nMasukkan %d bilangan Bulat !\n", n);
	int* data;
	data = new int [n];
	
	// Menginputkan nilai kedalam array data
	for(int i = 0; i < n; i++) {
		printf("     Masukkan data ke-%d : ", i+1);
		scanf("%d", &data[i]);
	}
	
	// Menampilkan data pada array serta hasil kuadratnya
	printf("\nData yang anda Masukkan adalah sebagai berikut :\n\n");
	for(int i = 0; i < n; i++) {
		printf("     Data ke-%d : %d\n", i+1, data[i]);
		printf("     Hasil kuadratnya : %d\n\n", data[i]*data[i]);
	}
	
	// Menampilkan data pada array yang merupakan bilangan gajil
	printf("\nData yang merupakan bilangan ganjil adalah sebagai berikut:\n\n");
	for(int i = 0; i < n; i++) {
		if(data[i] % 2 != 0) {
			printf("     Data ke-%d : %d\n", i+1, data[i]);
			printf("     Merupakan bilangan Ganjil\n\n");
		}
	}
	return 0;
}
