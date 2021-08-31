#include <cmath>
#include <iostream>
using namespace std;

int cariSelisihHari(int tahun) {
    //tahun Referensi adalah 1 january 1899 dengan wuku ke 21
    int refWuku = 21;
    int hari = 0;
    int minggu;
    for (int t = 1899; t < tahun; t++) {
        // Cek apakah Tahun Kabisat
        if ((t % 4 == 0 && t % 100 != 0) || t % 400 == 0) {
            hari += 366;
        }
        // Jika Bukan Tahun Kabisat
        else {
            hari += 365;
        }
    }
    return hari;
}

// Fungsi Mencari Wuku Awal Tahun untuk 1 januari tahun tersebut
int cariWukuAwalTahun(int tahun) {
    int minggu = cariSelisihHari(tahun);
    // Menghitung berapa minggu
    minggu = minggu / 7;
    // Ditambah referensi wuku
    minggu += 21;
    // cek jika hasil melebihi 30
    if (minggu > 30) {
        minggu %= 30;
    }
    return minggu;
}

int cariPancawara() {
}

// Mencari bulan penyesuaian
int bulanPenyesuaian(int bulan) {
    int nilai;
    switch (bulan) {
        case 1:
            nilai = -1;
            break;
        case 2:
            nilai = 0;
            break;
        case 3:
            nilai = 0;
            break;
        case 4:
            nilai = 0;
            break;
        case 5:
            nilai = 0;
            break;
        case 6:
            nilai = 1;
            break;
        case 7:
            nilai = 1;
            break;
        case 8:
            nilai = 1;
            break;
        case 9:
            nilai = 2;
            break;
        case 10:
            nilai = 2;
            break;
        case 11:
            nilai = 2;
            break;
        case 12:
            nilai = 2;
            break;
        default:
            break;
    }
    return nilai;
}

// Fungsi untuk mencari wuku
int cariWuku(float inputTanggal, int inputBulan, int inputTahun) {
    int wuku, hasilBagiTanggal, blnPenyesuaian,
        bulan = inputBulan - 1,
        // Jalankan fungsi mencari wuku awal tahun
        tahun = cariWukuAwalTahun(inputTahun);

    float tanggal = (inputTanggal) / 7;
    hasilBagiTanggal = round(tanggal);
    bulan *= 4;

    //Jalankan fungsi bulan penyesuaian
    blnPenyesuaian = bulanPenyesuaian(inputBulan);

    // Mencari Wuku
    wuku = hasilBagiTanggal + bulan + tahun;
    wuku += blnPenyesuaian;
    if (wuku > 30) {
        wuku %= 30;
    }
    return wuku;
}

// Fungsi Main
int main() {
    // Deklarasi variabel yang digunakan
    float tanggal;
    int tahun, bulan;
    int wuku, saptawara, pancawara;

    // Menerima input dari user
    cout << "Masukkan Tanggal Kelahiran : ";
    cin >> tanggal;
    cout << "Masukkan Bulan Kelahiran (Dalam angka, tanpa 0 didepannya) : ";
    cin >> bulan;
    cout << "Masukkan Tahun Kelahiran : ";
    cin >> tahun;

    // Jalankan Fungsi mencari wuku
    wuku = cariWuku(tanggal, bulan, tahun);

    cout << wuku << endl;

    return 0;
}