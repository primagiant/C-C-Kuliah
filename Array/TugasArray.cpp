#include <cstdio>

int main() {

	//Array Dinamis
	int jmlData;
	printf("Masukkan Jumlah Data yang akan diolah : ");
	scanf("%i", &jmlData);
	
	float* array;
	array = new float[jmlData];
	
	
	//Memasukkan nilai Kedalam Array	
	for (int i = 0; i < jmlData; i++) {
		printf("Masukkan nilai array ke-%i : ", i+1);
		scanf("%f", array+i);
	}


	//Menampilkan nilai dalam array
	printf("\nBilangan yang anda masukkan :\n");
	for (int i = 0; i < jmlData; i++) {
		printf("Nilai ke-%i : %.2f\n", i+1, array[i]);
	}
	

	//Mejumlahkan nilai dalam array dan menampilkan hasilnya
	float jumlah;
	printf("\nHasil Jumlah : ");
	for (int i = 0; i < jmlData; i++) {
		jumlah += array[i];
	}
	printf("%.2f\n", jumlah);
	
	
	//menghitung rata rata nilai dalam array
	float rata_rata = jumlah/jmlData;
	printf("Rata-rata : %.2f", rata_rata);
	
	
	return 0;
}
