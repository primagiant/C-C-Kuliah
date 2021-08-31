#include <iostream>
using namespace std;

int main() {
	
	int n = 5;
	int arr[n] = {5,3,2,4,1};
	int dummy;
	
	
	for( int i = 0; i < n; i++ ){
		for( int j = n-1; j > i; j--){
			if( arr[j] < arr[j-1]) {
				dummy = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = dummy;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
		
	return 0;
}
