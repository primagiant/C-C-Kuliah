#include <cstdio>

void BagiBulat(int a, int b, int* h, int* s)
{	
	*h = a/b;
	*s = a%b;
	
	return;
}

int main()
{
	int Bil1, Bil2, Hasil = 0, Sisa = 0;
	
	printf("Masukkan bilangan bulat yang akan dibagi: ");
	scanf("%i", &Bil1);
	printf("Masukkan bilangan bulat pembaginya: ");
	scanf("%i", &Bil2);
	
	BagiBulat(Bil1, Bil2, &Hasil, &Sisa);
	printf("\nHasil baginya = %i\n", Hasil);
	printf("\nSisa baginya = %i\n", Sisa);

	
	return 0;
}
