#include <cmath>
#include <iostream>
using namespace std;

// void bin(unsigned n) {
//     if (n > 1)
//         bin(n >> 1);
//     printf("%d", n & 1);
// }

void bintoDec(int num) {
    int hasil;
    int bin = 0;
    bin = bin << 1;
    for (int i = 0; i < 32; i++) {
        hasil = num & bin;
        cout << bin << " ";
        num = num << 1;
    }
}

int main(int argc, char const *argv[]) {
    int num;
    cin >> num;
    bintoDec(num);
    return 0;
}
