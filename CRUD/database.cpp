// Untuk file input dan output
#include <fstream>

// Standar input output c++
#include <iostream>

// Menggunkan type data String
#include <string>
using namespace std;

// Membuat
struct Mahasiswa {
    int id;  // Primary Key
    char nim[10];
    string nama;
    bool jenis_kelamin;
    char tahun_masuk[4];
    float ipk;
};

// Fungsi Membuat Menu
int databaseMenu() {
    system("cls");
    int input;
    cout << "**  Welcome to the Database **" << endl;
    cout << " 1. Tambah Data Mahasiswa" << endl;
    cout << " 2. Edit Mahasiswa" << endl;
    cout << " 3. Hapus Data Mahasiswa" << endl;
    cout << " 4. Kosongkan database" << endl;
    cout << " 5. Tampilkan semua Mahasiswa" << endl;
    cout << " 6. Cari Mahasiswa" << endl;
    cout << " 7. Quit" << endl;
    cout << "Pilih (1-7) : ";
    cin >> input;
    return input;
}

// Fungsi check apakah file database ada ?
void checkDatabase(fstream &data) {
    data.open("databse.bin", ios::out | ios::in | ios::binary);

    // cek jika database tidak ada
    if (data.is_open()) {
        return;
    } else {
        cout << "Database Tidak Ada, Buat Database" << endl;
        data.close();
        data.open("databse.bin", ios::trunc | ios::out | ios::in | ios::binary);
    }
}

// Fungsi Tambah Mahasiswa
int tambahMahasiswa(fstream &data) {
    Mahasiswa inputMahasiswa;
    cout << "Nama Mahasiswa : ";
    getline(cin, inputMahasiswa.nama);
}

main() {
    // Membuat fstream
    fstream data;

    checkDatabase(data);

    int opsi;
    do {
        // User memilih option
        opsi = databaseMenu();

        // Jika user memmilih angka selain 1-7 tampilkan error
        switch (opsi) {
            case 1:
                cout << "Tambah Mahasiswa\n";
                break;
            case 2:
                cout << "Edit Mahasiswa\n";
                break;
            case 3:
                cout << "Hapus Mahasiswa\n";
                break;
            case 4:
                cout << "Kosongkan database\n";
                break;
            case 5:
                cout << "Tampilkan Semua Mahasiswa\n";
                break;
            case 6:
                cout << "Cari Mahasiswa\n";
                break;
            case 7:
                return 7;

            default:
                cout << "Tolong pilih angka 1-7.\n";
                break;
        }
        system("pause");
    } while (opsi != 7);

    cout << "Program Selesai Dijalankan\n";
    cin.get();
    return 0;
}