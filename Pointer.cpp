#include <cstdio>
using namespace std;

int* X;
char* A;

int main()
{
	X = new int;
	*X = 0X01070C0F;
	A = (char*)X;
	
	printf("Nilai A ke 0 = %i, dengan bentuk heksadesimal = %X\n", A[0], A[0]);
	printf("Nilai A ke 1 = %d, dengan bentuk heksadesimal = %X\n", A[1], A[1]);
	printf("Nilai A ke 2 = %d, dengan bentuk heksadesimal = %X\n", A[2], A[2]);
	printf("Nilai A ke 3 = %d, dengan bentuk heksadesimal = %X\n", A[3], A[3]);

	return 0;
}
