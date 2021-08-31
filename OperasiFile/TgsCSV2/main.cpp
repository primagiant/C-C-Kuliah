#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

struct DataCSV {
    int id;
    char nama[100];
    char email[100];
    char gender[20];
    float ipk;
};

int exists(char *filename) {
    FILE *file;
    if ((file = fopen(filename, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

void createCSV(char *filename) {
    DataCSV data;
    // Konversi Data
    char id[100];
    char nama[100];
    char email[100];
    char gender[20];
    char ipk[100];

    // Buka File
    FILE *csvInput;

    // Cek File ada atau tidak
    if (exists(filename) == 1) {
        csvInput = fopen(filename, "a");

        printf("Masukkan Id : ");
        cin >> data.id;
        cin.ignore();

        printf("Masukkan Nama : ");
        gets(data.nama);
        printf("Masukkan email : ");
        gets(data.email);

        printf("Silakan pilih gender :\n");
        printf("Ketik (Pria / Wanita)\n");
        printf("\t:");
        gets(data.gender);

        printf("Masukkan ipk : ");
        cin >> data.ipk;
        cin.ignore();

        // id
        itoa(data.id, id, 10);
        strcat(id, ",");

        // nama
        strcpy(nama, data.nama);
        strcat(nama, ",");

        // email
        strcpy(email, data.email);
        strcat(email, ",");

        // gender
        strcpy(gender, data.gender);
        strcat(gender, ",");

        // ipk
        gcvt(data.ipk, 2, ipk);

        // Memasukkan Data;
        fputs(id, csvInput);
        fputs(nama, csvInput);
        fputs(email, csvInput);
        fputs(gender, csvInput);
        fputs(ipk, csvInput);
        fputs("\n", csvInput);
    } else {
        csvInput = fopen(filename, "w");
        // Masukkan nama kolom
        fputs("id,", csvInput);
        fputs("nama,", csvInput);
        fputs("email,", csvInput);
        fputs("gender,", csvInput);
        fputs("ipk", csvInput);
        fputs("\n", csvInput);
        cout << "File Tidak Ditemukan " << endl
             << "Membuat File ....." << endl;
    }
    fclose(csvInput);
}

int main(int argc, char const *argv[]) {
    char filename[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\TgsCSV2\\file.csv";
    char opsi;

    do {
        cout << "---------------------------------------------" << endl;
        cout << "     SELAMAT DATANG DI SISTEM WRITE DATA     " << endl;
        cout << "---------------------------------------------" << endl;

        createCSV(filename);

        printf("Lanjut (y/n) ? :");
        scanf("%s", &opsi);
        system("cls");

    } while (opsi == 'y' || opsi == 'Y');

    return 0;
}
