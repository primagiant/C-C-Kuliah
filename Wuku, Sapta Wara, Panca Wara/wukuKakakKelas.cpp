#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int kabisat(int tahunRef, int tahunDicari) {
    int hari = (tahunDicari / 4) - (tahunRef / 4);
    hari -= (tahunDicari / 100) - (tahunRef / 100);
    hari += (tahunDicari / 400) - (tahunRef / 400);
    return hari;
}

// Mencari tahun Kabisat
int cariTahun(int tahunRef, int tahunDicari) {
    int hari = 365 * (tahunDicari - tahunRef);
    hari += kabisat(tahunRef, tahunDicari - 1);
    return hari;
}

// Mencari selisih hari
int selisihHari(int tgl, int bln, int tahun) {
    bool kabisat;
    // Jika tahun kabisat
    if ((tahun % 4 == 0 && tahun % 100 != 0) || tahun % 400 == 0) {
        kabisat = true;
    } else {
        kabisat = false;
    }

    int hari;
    tgl -= 1;
    int Hari_bulan[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    if (bln <= 2) {
        hari = Hari_bulan[bln - 1] + tgl;
    } else {
        hari = Hari_bulan[bln - 1] + tgl;
        if (kabisat) {
            hari++;
        }
    }
    hari += cariTahun(1899, tahun);
    return hari;
}

int bulan(string bln) {
    string bulan_list[12] = {"januari",
                             "februari",
                             "maret",
                             "april",
                             "mei",
                             "juni",
                             "juli",
                             "agustus",
                             "september",
                             "oktober",
                             "november",
                             "desember"};
    int bulan;
    for (int i = 0; i <= 12; i++) {
        if (bln == bulan_list[i]) {
            bulan = i;
            break;
        }
        bulan = 13;
    }
    return bulan + 1;
}

int main(int argc, char *argv[]) {
    bool valid_input = true;
    int tgl, bln, tahun;

    if (argc == 1) {
        string blnstr;
        cout << "Masukan Tanggal Lahir : " << endl;
        cout << "Tanggal \t: ";
        cin >> tgl;
        cout << "Bulan \t\t: ";
        cin >> blnstr;
        bln = bulan(blnstr);
        cout << "Tahun \t\t: ";
        cin >> tahun;

        if ((bln > 12) || (tahun < 1899)) {
            valid_input = false;
        }

    } else if (argc = 4) {
        tgl = atoi(argv[1]);
        string blnstr(argv[2]);
        bln = bulan(blnstr);
        tahun = atoi(argv[3]);

        if ((bln > 12) || (tahun < 1899)) {
            valid_input = false;
        }
    }

    if (valid_input) {
        int selisihHr = selisihHari(tgl, bln, tahun);
        //harus dimulai dari 1 january 1899
        string saptaWaraList[7] = {"Redite", "Soma", "Anggara", "Budha", "Wrespati", "Sukra", "Saniscara"},
               pancaWaraList[5] = {"Paing",
                                   "Pon",
                                   "Wage",
                                   "Kliwon",
                                   "Umanis"},
               wukuList[30] = {"Matal",
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
                               "Dungulan"
                               "Kuningan",
                               "Langkir",
                               "Medangsia",
                               "Pujut",
                               "Pahang",
                               "Krulut",
                               "Merakih",
                               "Tambir",
                               "Medangkungan"};

        string saptawara, pancawara, wuku;
        int hasilHr = selisihHr % 7;
        saptawara = saptaWaraList[hasilHr];

        hasilHr = selisihHr % 5;
        pancawara = pancaWaraList[hasilHr];

        hasilHr = (selisihHr / 7) % 30;
        wuku = wukuList[hasilHr];

        cout << "\nHasilnya :" << endl;
        cout << "Saptawara \t: " << saptawara << endl
             << "Pancawara \t: " << pancawara << endl
             << "Wuku \t\t: " << wuku << endl;
    } else {
        cout << "INPUT TIDAK VALID" << endl
             << "hari di input seperti contoh : 1 january 2000" << endl
             << "hari yang di input tidak boleh sebelum 1 january 1899";
    }

    return 0;
}