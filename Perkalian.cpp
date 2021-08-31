#include <cstdio>


int main() {
	float alas, tinggi, luas_segitiga;
	
	printf("Masukkan Alas Segitiga : ");
	scanf("%f", &alas);
	
	printf("Masukkan Tinggi Segitiga : ");
	scanf("%f", &tinggi);
	
	luas_segitiga = alas * tinggi / 2;
	
	printf("Luas Segitiga = %.2f \n", luas_segitiga);
	printf("Didapat dari : (%.2f * %.2f) / 2 = %.2f", alas, tinggi, luas_segitiga);
	
	return 0;
}

