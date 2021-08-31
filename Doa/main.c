#include <stdio.h>

int main() {
    int jenis_kelamin, jenis_rambut;

    printf("Masukkan Jenis Kelamin Anda : \n");
    printf("1. Pria\n");
    printf("2. Wanita\n");
    printf("  Pilih : ");
    scanf("%i", &jenis_kelamin);

    printf("Masukkan Jenis Rambut Anda : \n");
    printf("1. Panjang\n");
    printf("2. Pendek\n");
    printf("  Pilih : ");
    scanf("%i", &jenis_rambut);

    if (jenis_kelamin == 1) {
        if (jenis_rambut == 1) {
            printf("Permen");
        }
        printf("Coklat");
    } else if (jenis_kelamin == 2) {
        if (jenis_rambut == 1) {
            printf("Permen");
        }
        printf("Coklat");
    } else {
        printf("Tolong masukkan sesuai 1 atau 2 saja");
    }

    return 0;
}