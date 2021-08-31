#include <cstdio>

float LuasPersegiPanjang(float p, float l)
{
	float luas;
	
	luas = p * l;
	
	return(luas);
}

int main()
{
	float panjang, lebar, luas;
	
	printf("Masukkan panjang persegi panjang (centimeter): ");
	scanf("%f", &panjang);
	printf("Masukkan lebar persegi panjang (centimeter): ");
	scanf("%f", &lebar);
	
	luas = LuasPersegiPanjang(panjang, lebar);
	printf("Luas persegi panjang = %.2f centimeter persegi", luas);
	
	return 0;
}
