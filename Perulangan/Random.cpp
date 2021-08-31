#include <cstdio>
// Berisikan Fungsi system(), rand(), dan srand()
#include <cstdlib>
// Berisikan Fungsi time()
#include <ctime>

// Membuat semua variabel yang dibutuhkan
char option;
int	num1,
	num2,
	jawabanUser,
	dikerjakan = 0,
	benar = 0,
	salah = 0,
	number = 1,
	operatorRandom;
float skor;

int main() {

	// Berguna untuk menampilakan bilangan random agar tidak monoton
	srand(time(NULL));
	
	do {
		printf("===========================================\n");
		printf("                MATEMATIKA\n");
		printf("===========================================\n");
		
		// Membuat angka random
		num1 = rand()%11;
		num2 = rand()%11;
		
		// Membuat Operasi Random ( + , - , *, bagi belum hehe)
		operatorRandom = rand()%3;
		
		printf("Berapakah Nilai dari :\n");
		// Pengkondisian Dengan Switch Case
		switch( operatorRandom ) {
			// jika 0 terjadi Penjumlahan
			case 0:
				printf("     %i. %i + %i = ",number, num1, num2);
				scanf("%i", &jawabanUser);
				// Pengkondisian dengan if dan else
				if(jawabanUser == num1 + num2) {
					benar += 1;
				} else {
					salah += 1;
				}			
				break;
			// jika 1 terjadi Pengurangan
			case 1:
				printf("     %i. %i - %i = ",number, num1, num2);
				scanf("%i", &jawabanUser);
				// Pengkondisian dengan if dan else
				if(jawabanUser == num1 - num2) {
					benar += 1;
				} else {
					salah += 1;
				}
				break;
			// jika 2 terjadi Perkalian
			case 2:
				printf("     %i. %i * %i = ", number, num1, num2);
				scanf("%i", &jawabanUser);
				// PEngkondisian dengan if dan else
				if(jawabanUser == num1 * num2) {
					benar += 1;
				} else {
					salah += 1;
				}	
				break;
		}
		
		number++;
		dikerjakan += 1;
		
		// Meminta nilai option
		printf("\nLanjut? (y/n): ");
		scanf("%1s", &option);
		
		// clear console
		system("cls");
		
	} while (option == 'y');
	
	// Keluar dari Pengulangan dan Menampilkan hasil
	printf("===========================================\n");
	printf("            Hasil Pengerjaan Soal\n");
	printf("===========================================\n\n");
	
	printf("     Soal Dikerjakan : %d\n", dikerjakan);
	printf("     Benar           : %d\n", benar);
	printf("     Salah           : %d\n", salah);
	
	// Perhitungan Skor
	skor = benar*100;
	skor = skor / dikerjakan;
	printf("     Skor = %.2f\n", skor);
	
	return 0;
}
