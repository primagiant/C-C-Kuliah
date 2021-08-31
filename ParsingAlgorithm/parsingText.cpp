#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    char text[255];
    char pemisah[2];
    cout << "Masukkan Input : ";
    gets(text);
    cout << "Pilih Pemisah (koma atau spasi): ";
    gets(pemisah);

    char *piece = strtok(text, pemisah);

    while (piece) {
        cout << piece << endl;
        piece = strtok(NULL, pemisah);
    }

    return 0;
}
