#include <cstdio>

int gelangDiTiang[3][100],
	jmlGelangDiTiang[3];
	
void menaraHanoi(int asal, int tujuan,int perantara, int jmlGelang) {
	if(jmlGelang == 1) {
		gelangDiTiang[tujuan][jmlGelangDiTiang[tujuan]] = gelangDiTiang[asal][jmlGelangDiTiang[asal]];
		jmlGelangDiTiang[tujuan]++;
		jmlGelangDiTiang[asal]--;
		printf("Memindahkan Gelang dari tiang ke-%d, ke tiang ke-%d\n", asal+1, tujuan+1);
	} else {
		menaraHanoi(asal, perantara, tujuan, jmlGelang - 1);
		menaraHanoi(asal, tujuan, perantara, 1);
		menaraHanoi(perantara, tujuan, asal, jmlGelang - 1);
	}
}

int main() {
	
	int jmlGelang;
	printf("Masuukan Jumlah Gelang : ");
	scanf("%d", &jmlGelang);
	
	jmlGelangDiTiang[0] = jmlGelang;
	jmlGelangDiTiang[1] = 0;
	jmlGelangDiTiang[2] = 0;
	
	menaraHanoi(0, 2, 1, jmlGelang);
	
	return 0;
}


