#include <cstdio>

int A;
int B;
int C;

int main()
{
	A = 5;
	B = 10;
	printf("Jawablah pertanyaan penjumlahan berikut.\n\n");
	printf("%i + %i = ", A, B);
	scanf("%i", &C);
	
	while (C != A + B)
	{
		printf("Maaf jawaban Anda salah, silahkan dicoba lagi...\n\n");
		printf("%i + %i = ", A, B);
		scanf("%i", &C);
	}
	
	printf("Selamat jewaban Anda benar...");
	return 0;
}
