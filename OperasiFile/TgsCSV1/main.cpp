#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define DataMax 100

struct DataCSV {
    int id;
    char nama_depan[100];
    char nama_belakang[100];
    char email[100];
    char gender[20];
    float ipk;
};

void printCSV(char* filename, DataCSV* data) {
    int row = 0;

    FILE* csvInput = fopen(filename, "r");
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), csvInput)) {
        int column = 0;
        row++;

        // Tidak Menghiraukan Baris Pertama
        if (row == 1)
            continue;

        // Memecah Data
        char* bagian = strtok(buffer, ",");

        while (bagian) {
            // Jika merupakan kolom id
            if (column == 0) {
                data[row - 1].id = atoi(bagian);
            }
            if (column == 1)
                strcpy(data[row - 1].nama_depan, bagian);
            if (column == 2)
                strcpy(data[row - 1].nama_belakang, bagian);
            if (column == 3)
                strcpy(data[row - 1].email, bagian);
            if (column == 4)
                strcpy(data[row - 1].gender, bagian);
            // jika kolom merupakan kolom IPK
            if (column == 5)
                data[row - 1].ipk = atof(bagian);

            bagian = strtok(NULL, ", ");
            column++;
        }
    }
    fclose(csvInput);
}

int main() {
    DataCSV data[DataMax];
    char filename[100] = "D:\\Documents\\Program\\C++\\OperasiFile\\TgsCSV1\\testcase.csv";

    printCSV(filename, data);

    int tampil;
    char opsi;

    do {
        cout << "--------------------------------------------" << endl;
        cout << "     SELAMAT DATANG DI SISTEM READ DATA     " << endl;
        cout << "--------------------------------------------" << endl;
        printf("Data Ke berapa Yang Ingin Anda Tampilkan ? : ");
        scanf("%d", &tampil);

        printf("Id\t\t: %d\n", data[tampil].id);
        printf("Nama Depan\t: %s\n", data[tampil].nama_depan);
        printf("Nama Belakang\t: %s\n", data[tampil].nama_belakang);
        printf("Email\t\t: %s\n", data[tampil].email);
        printf("Gender\t\t: %s\n", data[tampil].gender);
        printf("IPK\t\t: %.2f\n", data[tampil].ipk);

        printf("Lagi (y/n) ? :");
        scanf("%s", &opsi);
        system("cls");

    } while (opsi == 'y' || opsi == 'Y');

    return 0;
}