#include <iostream>
using namespace std;


int fibonaci(int n) {
	if(n==0){
		return 0;
	} else if (n==1 or n==2){
		return 1;
	} else if (n>=3) {
		return fibonaci(n-1) + fibonaci(n-2);
	}
}

main () {
	int n;
	int fibo = 1;
	
	cout<<"PLease Insert a Nummber : ";
	cin>>n;
	
	fibo = fibonaci(n);
	
	cout<<"Sum all from 0 to "<<n<<" is "<<fibo<<endl;
}
