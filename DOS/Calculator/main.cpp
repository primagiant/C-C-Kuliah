#include <iostream>//cout
#include <string>//string
#include <cstdlib>//atof()
#include <cmath>//log10() dan sqrt()
using namespace std;

int main(int argc, char** argv) {
	
	switch(argc) {
		case 3: {
			string word = argv[1];
			float bil = atof(argv[2]);
			
			string logaritma = "log",
					akarKuadrat = "akar",
					kuadrat = "kuadrat";
			if(word == logaritma) {
				cout << log10(bil);
			} else if (word == akarKuadrat) {
				cout << sqrt(bil);
			} else if (word == kuadrat) {
				cout << bil * bil;
			}else {
				cout << "Argument Tidak Valid";
			}
			break;
		}
		case 4: {
			char op = argv[2][0];
			float bil1 = atof(argv[1]), 
				  bil2 = atof(argv[3]);
				  
			switch(op) {
				case '+': {
					cout << bil1 + bil2;
					break;
				}
				case '-': {
					cout << bil1 - bil2;
					break;
				}
				case '*': {
					cout << bil1 * bil2;
					break;
				}
				case '/': {
					cout << bil1 / bil2;
					break;
				}
				default: {
					cout << "Argument Tidak Valid";
				}
			}
			break;
		}
		default: {
			cout << "Argument Tidak Valid";
			break;
		}
	}
	
	return 0;
}
