#include <iostream>
#include <string>
using namespace std;

int main() {
	
	while (true) {
		
		cout << "Program sederhana menggunakan while loop\n";
		
		// Stop Looping
		string op;
		cout << "Lanjut ? (Yes/No) : ";
		cin >> op;
		if(op == "Yes") {
			true;
		} else if(op == "No") {
			break;
		} else {
			cout << "Error (Input Salah!)";
			break;
		}
	}
}

