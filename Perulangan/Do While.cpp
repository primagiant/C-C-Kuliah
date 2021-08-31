#include <cstdio>

int A;
int Akumulasi;

int main()
{
	Akumulasi = 0;
	
	do
	{
		printf("Masukkan sembarang bilangan bulat: ");
		scanf("%i", &A);
		Akumulasi = Akumulasi + A;
		printf("Akumulasi dari bilangan-bilangan yang telah anda masukkan = %i\n\n", Akumulasi);
	}while (Akumulasi <= 100);
	
	printf("Selamat anda sudah berhasil mendapatkan Akumulasi melebihi 100.");
	return 0;
}
