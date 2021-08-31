#include <iostream>
using namespace std;

int sumingNumbers(int a) {
	if(a == 1){
		return 1;
	} else {
		return a + sumingNumbers(a-1);
	}
}

main() {
	int n;
	int result = 1;
	
	cout<<"PLease Insert a Nummber : ";
	cin>>n;
	
	result = sumingNumbers(n);
	
	cout<<"Sum all from 0 to "<<n<<" is "<<result<<endl;
}
