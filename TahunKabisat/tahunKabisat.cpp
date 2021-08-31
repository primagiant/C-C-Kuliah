#include <iostream>
using namespace std;

main()
{

	int x;

	cout << "Masukkan Tahun : ";
	cin >> x;

	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
	{
		cout << "Tahun Kabisat";
	}
	else
	{
		cout << "Bukan Kabisat";
	}
}
