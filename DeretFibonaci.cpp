#include <iostream>
using namespace std;

int main() {

	int n, a1 = 1, a2 = 0, hasil;
	cin >> n;
	//hasil = a1 + a2;
	
	for(int i = 1; i <= n; i++) {
		hasil = a1 + a2;
		a2 = a1;
		a1 = hasil;
		
		cout << hasil << " ";
	}

	cin.get();
	return 0;
}

