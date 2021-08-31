// boleh pke <cstdio> atau <stdio.h> sama
#include <math.h>  // digunakan agar bisa menggunakan pow()
#include <stdio.h>

// adalah fungsi untuk menegembalikan hasil
float LuasLingkaranKurangPersegi(float diameter) {
    // phi = 22/7 atau 3,14, kenapa berisi f , karena nilai float
    float phi = 3.14f;

    // pow(nilai, pangkat) misal pow(2, 3) = 2 pangkat 3
    // ini adalah diameter kuadrat
    float kuadratDiameter = pow(diameter, 2);

    // rumus luas lingkaran = 1/4 * phi * diameter kuadrat
    float luasLingkaran = kuadratDiameter * phi * 0.25f;

    // rumus persegi dari diagonal  = 1/2 * diameter kuadrat
    float luasPersegi = kuadratDiameter * 0.5;

    // Kembaikan hasil berupa luas lingkaran - luas persegi
    return luasLingkaran - luasPersegi;
}

int main() {
    // Buat variabel decimal dengan float
    float diameter, hasil;

    // Menerima input dari user
    printf("Panjang Diameter : ");
    scanf("%f", &diameter);

    // memanggil fungsi LuasLingkaranKurangPersegi dengan parameter (diameter)
    hasil = LuasLingkaranKurangPersegi(diameter);

    // tampilkan hasil
    printf("%.2f", hasil);
    // kenapa pakai %.2f agar hasil menggunakan 2 angka belakang koma

    return 0;
}