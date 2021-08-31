#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

struct Mhs {
    char nim[11];
    char nama[100];
    char jenis_kelamin[20];
    char tahun_lahir[5];
    char tahun_masuk[5];
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

void tambahData() {
    struct Mhs data;
    char filepath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\file.bin";
    // ambil input dari user
    printf("Masukkan NIM Mahasiswa (4 Digit Akhir) : ");
    gets(data.nim);

    // jika nim belum ada pada file
    if (!nimSama(filepath, data.nim)) {
        printf("Masukkan Nama Mahasiswa : ");
        gets(data.nama);
        printf("Masukkan Jenis Kelamin Mahasiswa (Pria/Wanita) : ");
        gets(data.jenis_kelamin);
        printf("Masukkan Tahun Lahir Mahasiswa : ");
        gets(data.tahun_lahir);
        printf("Masukkan Tahun Masuk Mahasiswa : ");
        gets(data.tahun_masuk);
        printf("Masukkan IPK Mahasiswa : ");
        scanf("%f", &data.ipk);

        FILE *dataMhs = fopen(filepath, "ab");

        if (dataMhs != NULL) {
            fwrite(&data, sizeof(struct Mhs), 1, dataMhs);
        } else {
            printf("Error : Opening File");
        }
        fclose(dataMhs);
    } else {  // jika nim sudah ada
        printf("Mahasiswa dengan nim tersebut sudah ada\n");
        printf("Tolong tambah mahasiswa dengan NIM lain\n");
    }
}

void bacaData() {
    struct Mhs data;
    char filepath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\file.bin";

    // Baca Data Dari yang Terbaru
    FILE *dataMhs = fopen(filepath, "rb");
    fseek(dataMhs, -sizeof(struct Mhs), SEEK_END);
    while (fread(&data, sizeof(struct Mhs), 1, dataMhs)) {
        // Print data
        printf("NIM\t\t: %s\n", data.nim);
        printf("Nama\t\t: %s\n", data.nama);
        printf("Jenis Kelamin\t: %s\n", data.jenis_kelamin);
        printf("Tahun Lahir\t: %s\n", data.tahun_lahir);
        printf("Tahun Masuk\t: %s\n", data.tahun_masuk);
        printf("IPK\t\t: %.2f\n\n", data.ipk);
        fseek(dataMhs, -2 * sizeof(struct Mhs), SEEK_CUR);
    };

    fclose(dataMhs);
}

void cariData() {
    struct Mhs data;
    char filepath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\file.bin";

    // User memilih nim yang dicari
    char nim_dicari[11];
    printf("Masukkan NIM mahasiswa yang ingin anda cari : ");
    gets(nim_dicari);

    bool ditemukan = false;

    FILE *dataMhs = fopen(filepath, "rb");
    while (fread(&data, sizeof(struct Mhs), 1, dataMhs)) {
        if (strstr(data.nim, nim_dicari)) {
            // jika data Ada
            printf("NIM\t\t: %s\n", data.nim);
            printf("Nama\t\t: %s\n", data.nama);
            printf("Jenis Kelamin\t: %s\n", data.jenis_kelamin);
            printf("Tahun Lahir\t: %s\n", data.tahun_lahir);
            printf("Tahun Masuk\t: %s\n", data.tahun_masuk);
            printf("IPK\t\t: %.2f\n\n", data.ipk);
            ditemukan = true;
        }
    }

    // cek data ditemukan atau tidak
    if (ditemukan == false) {
        printf("Data Mahasiswa Tidak Ditemukan\n");
    }
    fclose(dataMhs);
}

void hapusData() {
    struct Mhs data;
    char filepath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\file.bin";
    char tmpPath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\tmp.bin";

    // User memilih nim yang ingin dihapus
    char nim_dicari[11];
    printf("Masukkan NIM mahasiswa yang ingin anda hapus : ");
    gets(nim_dicari);

    bool dihapus = false;

    FILE *dataMhs = fopen(filepath, "rb");
    FILE *tmp = fopen(tmpPath, "wb");
    // jika file belum ada
    if (dataMhs == NULL) {
        printf("File belum dibuat data masih kosong!\n");
        printf("Buat file baru\n");
    } else {
        while (fread(&data, sizeof(struct Mhs), 1, dataMhs)) {
            if (strstr(data.nim, nim_dicari)) {
                // jika data Ada
                dihapus = true;
            } else {
                // jika data tidak ada tetap pindahkan data ke tmp
                fwrite(&data, sizeof(struct Mhs), 1, tmp);
            }
        }
        // cek data ditemukan atau tidak
        if (dihapus == false) {
            printf("Data Mahasiswa Tidak Ditemukan\n");
        } else {
            printf("1 Data Berhasil Dihapus\n");
        }
    }
    fclose(tmp);
    fclose(dataMhs);
    remove(filepath);
    rename(tmpPath, filepath);
}

void editData() {
    struct Mhs dataLama;
    char filepath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\file.bin";
    char tmpPath[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\Binary\\src\\tmp.bin";

    // User memilih nim yang diubah
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
        while (fread(&dataLama, sizeof(struct Mhs), 1, dataMhs)) {
            // jika data ada
            if (strstr(dataLama.nim, nim_dicari)) {
                ditemukan = true;
                //Print Data Lama
                printf("Data Sebelumnya : \n");
                printf("NIM\t\t: %s\n", dataLama.nim);
                printf("Nama\t\t: %s\n", dataLama.nama);
                printf("Jenis Kelamin\t: %s\n", dataLama.jenis_kelamin);
                printf("Tahun Lahir\t: %s\n", dataLama.tahun_lahir);
                printf("Tahun Masuk\t: %s\n", dataLama.tahun_masuk);
                printf("IPK\t\t: %.2f\n\n", dataLama.ipk);

                // Masukkan Data Baru
                struct Mhs newData;
                printf("Masukkan Data Baru : \n");
                printf("Masukkan NIM Mahasiswa (4 Digit Akhir) : ");
                gets(newData.nim);
                // cek jika nim yang diinput sudah ada
                // tapi boleh menginput nim lama
                if (strstr(dataLama.nim, newData.nim) || !nimSama(filepath, newData.nim)) {
                    printf("Masukkan Nama Mahasiswa : ");
                    gets(newData.nama);
                    printf("Masukkan Jenis Kelamin Mahasiswa (Pria/Wanita) : ");
                    gets(newData.jenis_kelamin);
                    printf("Masukkan Tahun Lahir Mahasiswa : ");
                    gets(newData.tahun_lahir);
                    printf("Masukkan Tahun Masuk Mahasiswa : ");
                    gets(newData.tahun_masuk);
                    printf("Masukkan IPK Mahasiswa : ");
                    scanf("%f", &newData.ipk);
                    fwrite(&newData, sizeof(struct Mhs), 1, tmp);
                    diedit = true;
                } else {
                    // pidahakan data lama ke file tmp
                    fwrite(&dataLama, sizeof(struct Mhs), 1, tmp);
                    printf("NIM yang anda masukkan sudah ada !\n");
                }
            } else {
                // pindahkan semua data ke file tmp
                fwrite(&dataLama, sizeof(struct Mhs), 1, tmp);
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
    // tutup file
    fclose(tmp);
    fclose(dataMhs);
    // hapus file lama
    remove(filepath);
    // ganti nama file baru menjadi nama file lama
    rename(tmpPath, filepath);
}

int menuTampilan() {
    int pilihan;
    printf("Program Database Mahasiswa\n");
    printf("1. Tambah Data\n");
    printf("2. Lihat Semua Data\n");
    printf("3. Cari Data\n");
    printf("4. Hapus Data\n");
    printf("5. Edit Data\n");
    printf("6. Exit\n");
    printf("Pilih : ");
    // mengambil pilihan user
    cin >> pilihan;
    system("cls");
    return pilihan;
}

int main() {
    /*** User Interface ***/
    bool loop = true;
    while (loop) {
        int pilihan = menuTampilan();
        switch (pilihan) {
            case 1:
                cin.ignore();
                tambahData();
                break;
            case 2:
                bacaData();
                break;
            case 3:
                cin.ignore();
                cariData();
                break;
            case 4:;
                cin.ignore();
                hapusData();
                break;
            case 5:
                cin.ignore();
                editData();
                break;
            case 6:
                loop = false;
                break;
        }
    }
    printf("Terimakasih Sudah Menggunakan Aplikasi ini\n");

    return 0;
}
