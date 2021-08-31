#include <cstdio>

void UbahNilai(int* a)
{
	printf("Isi a sebelum diisi 5 = %i\n\n", *a);
	*a = 5;
	printf("Isi a setelah diisi 5= %i\n\n", *a);	
	return;
}

int main()
{
	int Bil;
	
	Bil = 7;
	printf("Nilai Bil sebelum diubah = %i\n\n", Bil);
	UbahNilai(&Bil);
	printf("Nilai Bil setelah diubah = %i", Bil);
	
	return 0;
}
