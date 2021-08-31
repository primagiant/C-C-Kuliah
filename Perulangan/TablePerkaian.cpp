#include <cstdio>
// Untuk menggunkan system()
#include <cstdlib>

// membuat variabel yang dibutuhkan
char ulang;
int n;


int main() {
	
	do {
		
		printf("     SELAMAT DATANG DI PROGRAM TABEL PERKALIAN     \n\n");
		system("pause");
		system("cls");
			
		printf("Input Data Maksimal ? : ");
		scanf("%i", &n);
		
		// Print Garis Pembatas
		for(int j = 0; j <= n; j++) {
			printf("+-----");
		}
		printf("+\n");
	
		
		printf("|   x |");
		
		// Perulangan Bagian Atas
		for(int i = 1; i <= n; i++) {
			printf("%4i |", i);
		}
		printf("\n");
		
		// Print Garis Pembatas
		for(int j = 0; j <= n; j++) {
			printf("+-----");
		}
		printf("+\n");
		
		// Menampilkan hasil perkalian	
		for(int i = 1; i <= n; i++) {
			printf("| %3i |", i);
			for(int j = 1; j <= n; j++) {
					printf("%4i |", i*j);	
			}
			printf("\n");
			for(int j = 0; j <= n; j++) {
					printf("+-----");
			}
			printf("+\n");
		}
		
		// Memilih Kondisi
		printf("Apakah anda ingin menggunakan aplikasi lagi ? (y/n) : ");
		scanf("%1s", &ulang);
		
		// Clear console
		system("cls");
		
		
	} while(ulang == 'y');
	
	// clear console
	system("cls");
	printf("Terima Kasih Sudah Menggunakan Program Ini");
    return 0;
}
