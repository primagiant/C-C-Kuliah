#include <cstdio>
#include <cstdlib>

int main() {
	system("color a");
	int option;
	
	// Looping untuk mengulang program
	while( option != 2 ) {
		
		printf("==========================================================================\n");
		printf("                     Program Pengecekan Kelipatan\n");
		printf("==========================================================================\n");
		printf("1. Pengecekan\n");
		printf("2. Selesai\n\n");
		printf("Option : ");
		scanf("%d", &option);
		
		if(option == 1) { // jika user memilih 1
			
			//clear console
			system("cls");
			
			printf("==========================================================================\n");
			printf("                     Program Pengecekan Kelipatan\n");
			printf("==========================================================================\n");
			
			int* data;
			int n;
			
			// Menentukan berapa input data user
			printf(" Berapa Data Yang Ingin Anda Masukkan ? : ");
			scanf("%d", &n);
			
			// Membuat array dinamis
			data = new int [n];
			
			// Memasukkan bilngan yang ingin dinput user
			printf("\n Tolong Masukkan Bil. Kelipatan 3 dan Juga Merupakan Bil. Kelipatan 4\n");
			for(int i = 0; i < n; i++) {
				printf("     Masukkan Angka : ");
				scanf("%d", &data[i]);
			}
			
			// Menampilakan hasil pengecekan bilangan dari input user
			printf("\n Hasil Pengecekan :\n");
			for(int i = 0; i < n; i++) {
				if( (data[i] % 3 == 0) && (data[i] % 4 == 0) ) {
					printf("     Angka %d,'MERUPAKAN' Bilangan Kelipatan 3 dan 4\n", data[i]);
				} else {
					printf("     Angka %d,'BUKAN' Bilangan Kelipatan 3 dan 4\n",data[i]);
				}
			}
			
			// pause sampai user menekan sesuatu dan clear console
			system("pause");
			system("cls");
			
		} else if(option == 2) { // jika user memilih dua
			printf("\nSelesai\n");
		} else { // jika user tidak memilih 1 atau 2
			printf("\nTIDAK ADA PILIHAN %d\n", option);
			system("pause");
			system("cls");
		}
	}
	
	return 0;
}
