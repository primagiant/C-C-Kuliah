#include <iostream>
using namespace std;

int main() {
//	int n;
//	cin >> n;
	
	for(int i = 1; i <= 6; i ++) {
		for(int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	for(int i = 5; i > 0; i--) {
		for(int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cin.get();
	return 0;
}

