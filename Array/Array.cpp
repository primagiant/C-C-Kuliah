#include <cstdio>

//cara menuliskan constanta pada C++
//const int test = 10;

int main()
{
	int n;
	printf("Jumlah Data yang akan Dimasukkan : ");
	scanf("%d", &n);
	
	int a[n];
	
	for(int i = 0; i < n; i++) {
		printf("Masukkan nilai a ke %d : ", i);
		scanf("%d", &a[i]);	
	}
	
	printf("\n\nData yang anda masukkan adalah :\n");
	
	for(int i = 0; i < n; i++) {
		printf("Nilai a ke-%d = %d\n", i, a[i]);		
	}
	
	return 0;
}
