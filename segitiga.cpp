#include <iostream>
using namespace std;

int main() {

	float luas, alas, tinggi;

	cout << "masukkan Panjang alas : ";
	cin >> alas;
	cout << "masukkan Tinggi segitiga : ";
	cin >> tinggi;
	
	luas = alas * tinggi / 3;
	
	cout << luas;

	cin.get();
	return 0;
}

