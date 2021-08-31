#include <iostream>
#include <string>
using namespace std;

int main() {
	// Aplikasi Print Tulisan
	
	char huruf[10];
	
	for(int i = 0; i < 10; i++) {
		
		char x;
		cin >> x;
		huruf[i] = x;
		
		switch(huruf[i]) {
			case 1 :
				cout << "############" << endl;
				cout << "##        ##" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##        ##" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##  ####  ##" << endl;
				cout << "############" << endl;
			case 2 :
				cout << "############" << endl;
				cout << "##       ###" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##       ###" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##       ###" << endl;
				cout << "############" << endl;
			case 3 :
				cout << "############" << endl;
				cout << "##        ##" << endl;
				cout << "##  ########" << endl;
				cout << "##  ########" << endl;
				cout << "##  ########" << endl;
				cout << "##  ########" << endl;
				cout << "##        ##" << endl;
				cout << "############" << endl;
			case 4 :
				cout << "############" << endl;
				cout << "##       ###" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##  ####  ##" << endl;
				cout << "##       ###" << endl;
				cout << "############" << endl;	
			case 0 :
				break;
			default:
				break;
		}

	}


	cin.get();
	return 0;
}

