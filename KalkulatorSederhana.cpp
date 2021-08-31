#include <iostream>
#include <string>
using namespace std;

int main() {
	float n1, n2, hasil;
	string op;
	
	cout << "------------------------------------------------------" << endl;
	cout << "              Kalkulator Sederhana 2 Nilai            " << endl;
	cout << "------------------------------------------------------\n" << endl;
	
	cout << "Masuukan Angka pertama 		: ";
	cin >> n1;
	cout << "Masukkan Angka kedua 		: ";
	cin >> n2;
	
	cout << "Pilih Operator (+, -, *, /) 	: ";
	cin >> op;

	
	if(op == "+") {
		hasil = n1 + n2;
		cout << n1 << " + " << n2 << " = " << hasil;
	} else if (op == "-") {
		hasil = n1 - n2;
		cout << n1 << " - " << n2 << " = " << hasil;
	} else if (op == "*") {
		hasil = n1 * n2;
		cout << n1 << " * " << n2 << " = " << hasil;
	} else if (op == "/") {
		hasil = n1 / n2;
		cout << n1 << " / " << n2 << " = " << hasil;
	} else {
		cout << "Operator yang anda masukkan salah";
	}
	cout << endl;
	
	cout << "------------------------------------------------------" << endl;
	cout << "                    Program Selesai                   " << endl;
	cout << "------------------------------------------------------\n" << endl;
	
	
	cin.get();
	return 0;
}
