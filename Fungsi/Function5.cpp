#include <cstdio>

void HitungLuasPersegiPanjang(float p, float l, float* L)
{	
	*L = p * l;
	
	return;
}

int main()
{
	float panjang, lebar, luas;
	
	printf("Masukkan panjang persegi panjang (centimeter): ");
	scanf("%f", &panjang);
	printf("Masukkan lebar persegi panjang (centimeter): ");
	scanf("%f", &lebar);
	
	HitungLuasPersegiPanjang(panjang, lebar, &luas);
	printf("Luas persegi panjang = %.2f centimeter persegi", luas);
	
	return 0;
}
