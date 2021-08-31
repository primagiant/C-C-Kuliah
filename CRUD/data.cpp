#include <iostream>
#include <string>
using namespace std;

// Class Data untuk menampung data
class Data {
   public:
    string nim;  // Primary Key
    string nama;
    string jenis_kelamin;
    string tahun_lahir;
    string tahun_masuk;
    float ipk;
    Data *setelah;

    Data() {
        setelah = NULL;
    }
};

// Class Mahasiswa Untuk Menampung data semua mahasiswa dan methodnya
class Mahasiswa {
   private:
    Data *awal;
    Data *akhir;

   public:
    // Constructor
    Mahasiswa() {
        awal = akhir = NULL;
    }

    // Method mengecheck apakah ada nim yang sama
    bool duplikatData(string nim_target) {
        Data *mhs = awal;

        while (mhs != NULL) {
            if (mhs->nim == nim_target) {
                return true;
                break;
            }
            mhs = mhs->setelah;
        }
        if (mhs == NULL) {
            return false;
        }
    };

    // Method tambah Mahasiswa
    void tambahMahasiswa(string input_nim = {},
                         string input_nama = {},
                         string input_jenis_kelamin = {},
                         string input_tahun_lahir = {},
                         string input_tahun_masuk = {},
                         float input_ipk = 0.0f) {
        bool duplikat = duplikatData(input_nim);

        if (duplikat == true) {
            cout << "[Warning]:Mahasiswa dengan nim tersebut sudah terdata\n";
        } else {
            Data *mhs = new Data();
            // Input data
            mhs->nim = input_nim;
            mhs->nama = input_nama;
            mhs->jenis_kelamin = input_jenis_kelamin;
            mhs->tahun_lahir = input_tahun_lahir;
            mhs->tahun_masuk = input_tahun_masuk;
            mhs->ipk = input_ipk;

            if (akhir != NULL) {
                akhir->setelah = mhs;
                akhir = mhs;
            } else {
                akhir = awal = mhs;
            }
        }
    };

    // Method Menampilkan Semua data Mahasiswa
    void tampilkanSemuaMahasiswa() {
        Data *mhs = awal;
        while (mhs != NULL) {
            // Tampilkan Output
            cout << "NIM\t\t: " << mhs->nim << endl;
            cout << "Nama\t\t: " << mhs->nama << endl;
            cout << "Jenis Kelamin\t: " << mhs->jenis_kelamin << endl;
            cout << "Tahun Lahir\t: " << mhs->tahun_lahir << endl;
            cout << "Tahun Masuk\t: " << mhs->tahun_masuk << endl;
            cout << "IPK\t\t: " << mhs->ipk << endl;
            cout << endl;

            // Increment Pengulangan
            mhs = mhs->setelah;
        }
        cout << endl;
    };

    // Method Cari Mahasiswa
    void cariMahasiswa(string nim_target) {
        Data *mhs = awal;

        while (mhs != NULL) {
            if (mhs->nim == nim_target) {
                cout << "NIM\t\t: " << mhs->nim << endl;
                cout << "Nama\t\t: " << mhs->nama << endl;
                cout << "Jenis Kelamin\t: " << mhs->jenis_kelamin << endl;
                cout << "Tahun Masuk\t: " << mhs->tahun_lahir << endl;
                cout << "Tahun Masuk\t: " << mhs->tahun_masuk << endl;
                cout << "IPK\t\t: " << mhs->ipk << endl;
                cout << endl;
                break;
            }
            mhs = mhs->setelah;
        }
        if (mhs == NULL) {
            cout << "Mahasiswa yang anda cari tidak ada !" << endl
                 << endl;
        }
    };

    // Method Menghapus Mahasiswa
    void hapusMahasiswa(string nim_target) {
        bool duplikat = duplikatData(nim_target);
        if (duplikat == true) {
            Data *mhs = awal;
            // Kalau nim target sama dengan nim data pertama
            if (awal->nim == nim_target) {
                awal = mhs->setelah;
                if (awal == akhir) {
                    akhir = mhs->setelah;
                }
                delete mhs;
                cout << "Data Mahasiswa berhasil dihapus" << endl;
            }
            // Kalau nim target sama dengan nim data terakhir
            else if (akhir->nim == nim_target) {
                if (mhs != akhir) {
                    while (mhs->setelah != NULL) {
                        if (mhs->setelah == akhir) {
                            akhir = mhs;
                            mhs->setelah = NULL;
                            break;
                        }
                        mhs = mhs->setelah;
                    }
                } else {
                    awal = akhir = mhs->setelah;
                    delete mhs;
                }
                cout << "Data Mahasiswa berhasil dihapus" << endl;
            }
            // Kalau nim target bukan sama dengan nim data pertama maupun data terakhir
            else {
                while (mhs != NULL) {
                    if (mhs->setelah->nim == nim_target) {
                        Data *mhs2 = new Data();
                        mhs2 = mhs->setelah;
                        mhs->setelah = mhs2->setelah;
                        delete mhs2;
                        cout << "Data Mahasiswa berhasil dihapus" << endl;
                        break;
                    }
                    mhs = mhs->setelah;
                }
            }
        } else {
            cout << "Mahasiswa yang anda cari tidak ada !" << endl
                 << "Tidak ada data Yang Dihapus!" << endl
                 << endl;
        }
    };

    // Method Edit Mahasiswa
    void editMahasiswa(string nim_target = {},
                       string input_nama = {},
                       string input_jenis_kelamin = {},
                       string input_tahun_lahir = {},
                       string input_tahun_masuk = {},
                       float input_ipk = float(0.0f)) {
        Data *mhs = awal;
        while (mhs != NULL) {
            if (mhs->nim == nim_target) {
                // Input data
                // cek jika string kosong
                nim_target.empty() ? mhs->nim = mhs->nim : mhs->nim = nim_target;
                input_nama.empty() ? mhs->nama = mhs->nama : mhs->nama = input_nama;
                input_jenis_kelamin.empty() ? mhs->jenis_kelamin = mhs->jenis_kelamin : mhs->jenis_kelamin = input_jenis_kelamin;
                input_tahun_lahir.empty() ? mhs->tahun_lahir = mhs->tahun_lahir : mhs->tahun_lahir = input_tahun_lahir;
                input_tahun_masuk.empty() ? mhs->tahun_masuk = mhs->tahun_masuk : mhs->tahun_masuk = input_tahun_masuk;
                // cek jika ipk kosong
                (input_ipk == float(0.0f)) ? mhs->ipk = mhs->ipk : mhs->ipk = input_ipk;
                break;
            }
            mhs = mhs->setelah;
        }
        if (mhs == NULL) {
            cout << "Mahasiswa yang anda cari tidak ada !" << endl
                 << "Tidak ada data Yang Diedit!" << endl
                 << endl;
        }
    };
};

// Cek apakah sebuah string adalah number
// misal "32" adalah number 32
bool is_number(const string &s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// Membuat Fungsi Menu
int menuDatabase() {
    system("cls");
    int input;
    cout << "**  SISTEM DATABASE MAHASISWA **" << endl;
    cout << " 1. Tambah Data Mahasiswa" << endl;
    cout << " 2. Edit Mahasiswa" << endl;
    cout << " 3. Hapus Data Mahasiswa" << endl;
    cout << " 4. Tampilkan semua Mahasiswa" << endl;
    cout << " 5. Cari Mahasiswa" << endl;
    cout << " 6. Quit" << endl;
    cout << "Pilih (1-6) : ";
    cin >> input;
    return input;
}

// Fungsi Cek NIM
string cekNIM() {
    string nim;
    cout << "Masukkan NIM anda \t: ";
    cin >> nim;
    // Jika input bukan angka
    if (is_number(nim)) {
        // NIM Harus 10 digit
        if (nim.length() == 10) {
            return nim;
        } else {
            cout << "[Warning:!!] NIM harus 10 digit" << endl;
            cekNIM();
        }
    } else {
        cout << "[Warning:!!] Input harus angka" << endl;
        cekNIM();
    }
}

// Fungsi untuk pilih Jenis kelamin
string pilihGender() {
    int opsiGender;
    string jenis_kelamin;
    cout << "Masukkan Gender anda" << endl
         << "1. Pria" << endl
         << "2. Wanita" << endl
         << "Pilih : ";

    cin >> opsiGender;

    switch (opsiGender) {
        case 1:
            jenis_kelamin = "Pria";
            break;
        case 2:
            jenis_kelamin = "Wanita";
            break;
        default:
            cout << "[Warning:!!] Tolong Pilih 1 atau 2!" << endl;
            pilihGender();
            break;
    }
    return jenis_kelamin;
}

// Fungsi Cek Tahun
string cekTahun() {
    string thnMasuk;
    cin >> thnMasuk;
    // Jika input bukan angka
    if (is_number(thnMasuk)) {
        // Tahun Masuk Harus 4 digit
        if (thnMasuk.length() == 4) {
            return thnMasuk;
        } else {
            cekTahun();
            cout << "[Warning:!!] Tahun harus 4 digit Angka" << endl;
        }
    } else {
        cout << "[Warning:!!] Input harus angka" << endl;
        cekTahun();
    }
}

// Fungsi Cek IPK
float cekIPK() {
    float ipk;
    cout << "Masukkan IPK anda \t: ";
    cin >> ipk;
    // Jika IPK lebih dari 4 dan kurang dari 0
    if (ipk <= 4.0f && ipk >= 0.0f) {
        return ipk;
    } else {
        cout << "[Warning:!!] Harus kurang dari 4 dan lebih dari 0" << endl
             << "\t- Boleh Decimal" << endl;
        cekIPK();
    }
}

// Fungsi menampilkan Menu Tambah Mahasiswa
void menuTambahMahasiswa(Mahasiswa mhs) {
    system("cls");
    //deklarasi varibel
    string nim, nama, jenis_kelamin, tahun_lahir, tahun_masuk;
    float ipk;

    cout << "**  Menu Tambah Mahasiswa **" << endl;

    // Cek semua input
    nim = cekNIM();
    cout << "Masukkan Nama anda \t: ";
    cin.ignore();
    getline(cin, nama);

    jenis_kelamin = pilihGender();

    cout << "Masukkan Tahun Lahir anda \t: ";
    tahun_lahir = cekTahun();

    cout << "Masukkan Tahun Masuk anda \t: ";
    tahun_masuk = cekTahun();

    ipk = cekIPK();

    // Jalanka Method tambah Mahasiswas
    mhs.tambahMahasiswa(nim, nama, jenis_kelamin, tahun_lahir, tahun_masuk, ipk);
}

// fungsi pilih edit
int pilihEditMahasiswa() {
    cout << endl;
    int input;
    cout << "**  Pilih yang mau di edit **" << endl;
    cout << " 1. Edit NIM" << endl;
    cout << " 2. Edit Nama" << endl;
    cout << " 3. Edit Jenis Kelamin" << endl;
    cout << " 4. Edit Tahun Lahir" << endl;
    cout << " 5. Edit Tahun Masuk" << endl;
    cout << " 6. Edit IPK" << endl;
    cout << " 7. Cancel" << endl;
    cout << "Pilih (1-7) : ";
    cin >> input;
    return input;
}

// Fungsi menampilkan Menu Edit Mahasiswa
void menuEditMahasiswa(Mahasiswa mhs) {
    system("cls");

    //deklarasi varibel
    string nim_target, nama, jenis_kelamin, tahun_lahir, tahun_masuk;
    float ipk;

    cout << "**  Menu Edit Mahasiswa **" << endl;

    cout << "Masukkan Id Target anda \t: ";
    cin >> nim_target;

    mhs.cariMahasiswa(nim_target);
    char pilihan;

    do {
        int opsiEdit = pilihEditMahasiswa();

        // Kondisi mengubah / mengedit data
        switch (opsiEdit) {
            case 1:
                nim_target = cekNIM();
                break;
            case 2:
                cout << "Masukkan Nama anda \t: ";
                cin.ignore();
                getline(cin, nama);
                break;
            case 3:
                jenis_kelamin = pilihGender();
                break;
            case 4:
                tahun_lahir = cekTahun();
                break;
            case 5:
                tahun_masuk = cekTahun();
                break;
            case 6:
                ipk = cekIPK();
                break;
            default:
                break;
        }

        // Kondisi selesai while
        cout << "Mau Ubah Yang lain ? (y/n) : ";
        cin >> pilihan;

        // Jalankan Method edit mahasiswa
        mhs.editMahasiswa(nim_target, nama, jenis_kelamin, tahun_lahir, tahun_masuk, ipk);
    } while (pilihan == 'y');
}

// Menu Delete Mahasiswa
void menuHapusMahasiswa(Mahasiswa mhs) {
    string nim_target;
    cout << "**  Menu Hapus Mahasiswa **" << endl;
    nim_target = cekNIM();
    mhs.hapusMahasiswa(nim_target);
}

// Menu cari Mahasiswa
void menuCariMahasiswa(Mahasiswa mhs) {
    string nim_target;
    cout << "**  Menu Cari Mahasiswa **" << endl;
    nim_target = cekNIM();
    mhs.cariMahasiswa(nim_target);
}

// Main Fungsi
int main() {
    Mahasiswa mhs;

    // Data Dummy
    mhs.tambahMahasiswa("2015101039", "Ketut Yudi Witanarya", "Pria", "2001", "2020", 3.75);
    mhs.tambahMahasiswa("2015101031", "Ony Andewi", "Wanita", "2002", "2020", 3.83);
    mhs.tambahMahasiswa("2015101028", "I Gusti Ngurah Agung Nata Kusuma", "Pria", "2001", "2020", 3.72);
    mhs.tambahMahasiswa("2015101036", "Dewa Kadek Deva Sastrawan", "Pria", "2002", "2020", 3.69);
    mhs.tambahMahasiswa("2015101035", "Gede Arya Ardivan Pratama Saputra", "Pria", "2002", "2020", 3.8);
    mhs.tambahMahasiswa("2015101034", "Kadek Prima Giant Marta Dinata", "Pria", "2002", "2020", 3.9);

    int opsi;
    do {
        // User memilih option
        opsi = menuDatabase();

        // Jika user memilih angka selain 1-7 tampilkan error
        switch (opsi) {
            case 1:
                menuTambahMahasiswa(mhs);
                break;
            case 2:
                menuEditMahasiswa(mhs);
                break;
            case 3:
                menuHapusMahasiswa(mhs);
                break;
            case 4:
                mhs.tampilkanSemuaMahasiswa();
                break;
            case 5:
                menuCariMahasiswa(mhs);
                break;
            case 6:
                cout << "Sistem Dihentikan!!\n";
                system("pause");
                return 6;
            default:
                cout << "Tolong pilih angka 1-6.\n";
                cout << "Sistem Dihentikan!!\n";
                system("pause");
                return 6;
                break;
        }
        system("pause");
    } while (opsi != 6);

    cin.get();

    return 0;
}