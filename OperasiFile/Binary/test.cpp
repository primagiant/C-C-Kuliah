#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

struct Mhs {
    char nim[11];
    char nama[100];
    char jenis_kelamin[20];
    char tahun_masuk[4];
    float ipk;
};

// cek nim sama
bool nimSama(char *filepath, char nim[11]) {
    struct Mhs data;
    FILE *dataMhs = fopen(filepath, "rb");
    while (fread(&data, sizeof(struct Mhs), 1, dataMhs)) {
        if (strstr(data.nim, nim)) {
            // Data Ada
            fclose(dataMhs);
            return true;
        }
    }
    fclose(dataMhs);
    return false;
}

void editData() {
    struct Mhs data;
    char filepath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\file.bin";
    char tmpPath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\tmp.bin";

    // User memilih nim yang dicari
    char nim_dicari[11];
    printf("Masukkan NIM mahasiswa yang ingin anda Edit : ");
    gets(nim_dicari);

    bool ditemukan = false;
    bool diedit = false;

    FILE *dataMhs = fopen(filepath, "rb");
    FILE *tmp = fopen(tmpPath, "wb");
    if (dataMhs == NULL) {
        printf("File belum dibuat data masih kosong!\n");
    } else {
        while (fread(&data, sizeof(struct Mhs), 1, dataMhs)) {
            if (strstr(data.nim, nim_dicari)) {
                // Data Ada
                ditemukan = true;
                //Print Data Lama
                printf("Data Sebelumnya : \n");
                printf("NIM\t\t: %s\n", data.nim);
                printf("Nama\t\t: %s\n", data.nama);
                printf("Jenis Kelamin\t: %s\n", data.jenis_kelamin);
                printf("Tahun Masuk\t: %s\n", data.tahun_masuk);
                printf("IPK\t\t: %.2f\n\n", data.ipk);

                // Masukkan Data Baru
                struct Mhs newData;
                printf("Masukkan Data Baru : \n");
                printf("Masukkan NIM Mahasiswa (4 Digit Akhir) : ");
                gets(newData.nim);

                if (strstr(data.nim, newData.nim) || !nimSama(filepath, newData.nim)) {
                    printf("Masukkan Nama Mahasiswa : ");
                    gets(newData.nama);
                    printf("Masukkan Jenis Kelamin Mahasiswa (Pria/Wanita) : ");
                    gets(newData.jenis_kelamin);
                    printf("Masukkan Tahun Masuk Mahasiswa : ");
                    gets(newData.tahun_masuk);
                    printf("Masukkan IPK Mahasiswa : ");
                    scanf("%f", &newData.ipk);
                    fwrite(&newData, sizeof(struct Mhs), 1, tmp);
                    diedit = true;
                } else {
                    fwrite(&data, sizeof(struct Mhs), 1, tmp);
                    printf("NIM yang anda masukkan sudah ada !\n");
                }
            } else {
                fwrite(&data, sizeof(struct Mhs), 1, tmp);
            }
        }
        // cek data ditemukan atau tidak
        if (ditemukan == false) {
            printf("Data Mahasiswa Tidak Ditemukan\n");
        }
        // cek data berhasil diedit
        if (diedit == true) {
            printf("Data Berhasil diedit\n");
        } else {
            printf("Data Gagal diedit\n");
        }
    }
    fclose(tmp);
    fclose(dataMhs);
    remove(filepath);
    rename(tmpPath, filepath);
}

int main(int argc, char const *argv[]) {
    editData();
    return 0;
}
