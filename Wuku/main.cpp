#include <cmath>
#include <iostream>
using namespace std;

int cariWukuAwalTahun(int inputTahun) {
    int refWuku = 14;
    int h = 0;
    int wuku;

    for (int t = 1900; t < inputTahun; t++) {
        if ((inputTahun % 4 == 0 || inputTahun % 100 == 0) && inputTahun % 400 == 0) {
            h += 366;
        } else {
            h += 365;
        }
    }

    wuku = h / 7;
    if (wuku > 30) {
        wuku %= 30;
    }

    return wuku;
}

int cariWuku(float inputTgl, int inputBln, int inputThn) {
    int hasil;
    float tglFloat = round(inputTgl / 7);

    int tgl = int(tglFloat);
    bln = ((inputBln - 1) * 4),
    thn = cariWukuAwalTahun(inputThn),
    blnPenyesuaian = bulanPenyesuaian(inputBln);

    hasil = tgl + bln + thn + blnPenyesuaian;

    return hasil;
}