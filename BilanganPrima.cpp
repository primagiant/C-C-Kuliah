#include <iostream>
using namespace std;

int main() {
	int i1, i2, faktor;
	cout << "MENCARI BIlANGAN PRIMA DENGAN INTERFAL" << endl;
	cout << "Bilangan Prima Dengan Interfal : " << endl;
	cin >> i1;
	cout << "|\n";
	cin >> i2;
	
	if (i2 > i1) {
	
		for(int i = i1; i <= i2; i++) {
			faktor = 0;
			for(int j = 1; j <= i; j++) {
				if(i % j == 0) {
					faktor += 1;
				}
			}
			
			if (faktor == 2) {
				cout << i << " ";
			}
	
		}
		
	} else {
		cout << "Nilai pertama harus lebih kecil dari nilai kedua";
	}
	
}
