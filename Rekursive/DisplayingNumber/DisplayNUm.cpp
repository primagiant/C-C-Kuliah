#include <iostream>
using namespace std;

void displayNum(int n) {
	int i = 0;
	if(i==n){
		cout<<i<<" ";
		displayNum(i+1);
	}
}

main() {
	int n;
	
	cout<<"PLease Insert a Nummber : ";
	cin>>n;

	displayNum(n);
	
}
