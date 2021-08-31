#include <iostream>
using namespace std;

int main() {

	float volume, tinggi, pjang, lebar;
	
	cout << "Panjang alas :";
	cin >> pjang;
	cout << "Lebar alas :";
	cin >> lebar;
	cout << "Tinggi limas :";
	cin >> tinggi;
	
	volume = pjang* tinggi * lebar / 3;
	
	cout << volume;

	cin.get();
	return 0;
}

