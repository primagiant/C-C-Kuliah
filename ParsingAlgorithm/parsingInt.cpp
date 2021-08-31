#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    float hasil = 0, konversi;
    char text[255];
    char pemisah[2];
    cout << "Masukkan Input : ";
    gets(text);
    cout << "Pilih Pemisah (koma atau spasi): ";
    gets(pemisah);

    char *piece = strtok(text, pemisah);

    while (piece) {
        konversi = stof(piece);
        hasil += konversi;
        piece = strtok(NULL, pemisah);
    }

    cout << hasil << endl;

    return 0;
}
