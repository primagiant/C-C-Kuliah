#include <cstdio>
#include <cstdlib>

float LuasSegitiga(float a, float b) {
	float luas;
	luas = a * b * 0.5;
	return luas;
}

float VolumeBalok(float a, float b, float c) {
	float volume;
	volume = a * b * c;
	return volume;
}

int main () {
	
	float pSegitiga,
		aSegitiga,
		pBalok,
		lBalok,
		tBalok,
		volume,
		luas;
	char ulang,
		exit;
	int pilihan;
			
	do {
		printf("================================================\n");
		printf("      APLIKASI PENGHITUNG LUAS DAN VOLUME      \n");
		printf("================================================\n");
		printf("Pilih App :\n");
		printf("     1. Luas Segitiga\n");
		printf("     2. Volume Balok\n");
		printf("     3. Exit\n");
		printf("Pilih : ");
		scanf("%i", &pilihan);
		
		if ( pilihan != 3) {
			switch(pilihan) {
				case 1:
					system("cls");
					printf("================================================\n");
					printf("      APLIKASI PENGHITUNG LUAS SEGITIGA      \n");
					printf("================================================\n");
					printf("Masukkan Panjang Segitiga : ");
					scanf("%f", &pSegitiga);
					printf("Masukkan Alas Segitiga : ");
					scanf("%f", &aSegitiga);
					luas = LuasSegitiga(pSegitiga, aSegitiga);
					printf("Hasil : %.2f\n\n", luas);
					break;
				case 2:
					system("cls");
					printf("================================================\n");
					printf("      APLIKASI PENGHITUNG VOLUME BALOK    \n");
					printf("================================================\n");
					printf("Masukkan Panjang Balok : ");
					scanf("%f", &pBalok);
					printf("Masukkan Lebar Balok : ");
					scanf("%f", &lBalok);
					printf("Masukkan Tinggi Balok : ");
					scanf("%f", &tBalok);
					volume = VolumeBalok(pBalok, lBalok, tBalok);
					printf("Hasil : %.2f\n\n", volume);
					break;
				default:
					printf("Pilihan tidak ada !\n");
					break;
			}
			printf("Jalankan Program Lagi ? (y/n) : ");
			scanf("%2s", &ulang);
			system("cls");	
		} else {
			printf("Exit ? (y/n) : ");
			scanf("%2s", &exit);
			system("cls");	
		}
		
	} while (ulang == 'y' || exit == 'n');
	
	printf("================================================\n");
	printf("  Trimakasih Sudah Menggunakan Aplikasi ini :v\n");
	printf("================================================");
	
	return 0;
}
