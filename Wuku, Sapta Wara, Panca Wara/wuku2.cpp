#include <iostream>
#include <string>
using namespace std;

// Cek tahun kabisat
int cekTahunKabisat(int tahun) {
    int jmlHr;
    if ((tahun % 4 == 0 && tahun % 100 != 0) || tahun % 400 == 0) {
        jmlHr = 366;
    } else {
        jmlHr = 365;
    }
    return jmlHr;
}

// Cari hari dalam setiap bulan
int cariBulan(int bulan, int tahun) {
    int bln[12] = {31, 28, 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31};

    if (cekTahunKabisat(tahun) == 366) {
        bln[1] = 29;
    }

    return bln[bulan - 1];
}

// Fungsi Print saptawara
void cariSaptawara(int jmlHari) {
    //1 januari 1899 adalah Minggu
    switch (jmlHari % 7) {
        case 1:
            cout << "Redite ";
            break;
        case 2:
            cout << "Soma ";
            break;
        case 3:
            cout << "Anggara ";
            break;
        case 4:
            cout << "Budha ";
            break;
        case 5:
            cout << "Wrespati ";
            break;
        case 6:
            cout << "Sukra ";
            break;
        case 0:
            cout << "Saniscara ";
            break;
        default:
            cout << "Error ";
            break;
    }
}

// Fungsi Print pancawara
void cariPancawara(int jmlHari) {
    //1 januari 1899 adalah Pahing
    switch (jmlHari % 5) {
        case 1:
            cout << "Pahing ";
            break;
        case 2:
            cout << "Pon ";
            break;
        case 3:
            cout << "Wage ";
            break;
        case 4:
            cout << "Kliwon ";
            break;
        case 0:
            cout << "Umanis ";
            break;
        default:
            cout << "Error ";
            break;
    }
}

// Fungsi Print Wuku
void cariWuku(int jmlHari) {
    jmlHari = (jmlHari / 7) % 30;

    //1 januari 1899 adalah langkir
    string wukuList[30] = {
        "Matal",
        "Uye",
        "Menail",
        "Prangbakat",
        "Bala",
        "Ugu",
        "Wayang",
        "Kelawu",
        "Dukut",
        "Watugunung",
        "Sinta",
        "Landep",
        "Ukir",
        "Kulantir",
        "Tolu",
        "Gumbreg",
        "Wariga",
        "Warigadean",
        "Julungwangi",
        "Sungsang",
        "Dungulan",
        "Kuningan",
        "Langkir",
        "Medangsia",
        "Pujut",
        "Pahang",
        "Krulut",
        "Merakih",
        "Tambir",
        "Medangkungan",
    };

    string wuku = wukuList[jmlHari];
    cout << wuku;
}

int main() {
    int tgl, bln, thn;
    int hasilHr, hasilBln, hasilThn;
    int thnRef = 1899;

    cout << "Masukkan Tangaal : ";
    cin >> tgl;
    cout << "Masukkan Bulan : ";
    cin >> bln;
    cout << "Masukkan Tahun : ";
    cin >> thn;

    //total hari dari tanggal 1 januari 1899 sampai dengan sebelum awal tahun yg dimaksud
    for (int i = 1899; i < thn; i++) {
        hasilHr += cekTahunKabisat(i);
    }

    //total hari hingga sebelum awal bulan yg dimaksud
    for (int i = 1; i < bln; i++) {
        hasilHr += cariBulan(i, thn);
    }

    //total hari hingga tanggal yg dimaksud
    hasilHr += tgl;

    //print output
    cariSaptawara(hasilHr);
    cariPancawara(hasilHr);
    cariWuku(hasilHr);
}