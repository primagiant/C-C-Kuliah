#include <iostream>
using namespace std;

const char *newName(string str);
void toNegative(string path);
void toGrayscale(string path);
void swapColor(string path);
void increaseBrightness(string path);

int main(int argc, char const *argv[]) {
    short opt;
    cout << "|======================================|\n";
    cout << "+   Program Editing BMP Image 24 Bit   +\n";
    cout << "|======================================|\n";
    cout << "Pilih Opsi Editing :\n"
         << "1. Negative\n"
         << "2. Grayscale\n"
         << "3. Swap Color\n"
         << "4. Increase Brightness\n"
         << "5. Exit\n";
    cout << "Pilihan : ";
    scanf("%d", &opt);

    // Mengambil Input dari user
    char str[30];

    if (opt == 1) {  // Negative BMP
        cout << "nama file BMP :";
        scanf(" %[^\n]%*c", str);
        string path(str);
        toNegative(path);
    } else if (opt == 2) {  // Grayscale BMP
        cout << "nama file BMP :";
        scanf(" %[^\n]%*c", str);
        string path(str);
        toGrayscale(path);
    } else if (opt == 3) {  // Swap Color BMP
        cout << "nama file BMP :";
        scanf(" %[^\n]%*c", str);
        string path(str);
        swapColor(path);
    } else if (opt == 4) {  // Increase Brightness
        cout << "nama file BMP :";
        scanf(" %[^\n]%*c", str);
        string path(str);
        increaseBrightness(path);
    } else if (opt == 5) {
        cout << "Thanks";
    } else {
        cout << "INVALID INPUT\n";
    }
    return 0;
}

const char *newName(string str, string label) {  // Membuat nama file baru untuk file hasil edit
    str.replace(str.length() - 4, 1, label);
    const char *newfilename = &str[0];
    return newfilename;
}

void toNegative(string path) {
    int width, heigth, padding;
    const char *filedir = &path[0];
    char buf[100];
    string label = "_negative.";

    FILE *fin = fopen(filedir, "rb");
    FILE *fout = fopen(newName(path, label), "wb");

    // Mengambil tinggi dan lebar image
    fseek(fin, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fin);
    fread(&heigth, sizeof(int), 1, fin);

    // hitung padding yg dibutuhkan
    padding = (4 - ((width * 3) % 4)) % 4;

    // balik ke awal;
    rewind(fin);
    fread(buf, sizeof(char), 54, fin);
    fwrite(buf, sizeof(char), 54, fout);

    for (int y = 0; y < heigth; y++) {     // perulangan ke tinggi
        for (int x = 0; x < width; x++) {  // perulangan ke lebar
            fread(buf, sizeof(char), 3, fin);
            // Gambar Negative
            for (int i = 0; i < 3; i++)
                buf[i] = ~buf[i];
            fwrite(buf, sizeof(char), 3, fout);
        }
        for (int x = 0; x < padding; x++) {  // menambahkan padding
            fread(buf, sizeof(char), 1, fin);
            fwrite(buf, sizeof(char), 1, fout);
        }
    }

    fclose(fin);
    fclose(fout);
}

void toGrayscale(string path) {
    int width, heigth, padding;
    const char *filedir = &path[0];
    char buf[100];
    string label = "_grayscale.";

    FILE *fin = fopen(filedir, "rb");
    FILE *fout = fopen(newName(path, label), "wb");

    // Mengambil tinggi dan lebar image
    fseek(fin, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fin);
    fread(&heigth, sizeof(int), 1, fin);

    // hitung padding yg dibutuhkan
    padding = (4 - ((width * 3) % 4)) % 4;

    // balik ke awal;
    rewind(fin);
    fread(buf, sizeof(char), 54, fin);
    fwrite(buf, sizeof(char), 54, fout);

    for (int y = 0; y < heigth; y++) {     // perulangan ke tinggi
        for (int x = 0; x < width; x++) {  // perulangan ke lebar
            fread(buf, sizeof(char), 3, fin);
            // Gambar Grayscale
            buf[0] = (buf[0] + buf[1] + buf[2]) / 3;
            buf[1] = buf[0];
            buf[2] = buf[0];
            fwrite(buf, sizeof(char), 3, fout);
        }
        for (int x = 0; x < padding; x++) {  // menambahkan padding
            fread(buf, sizeof(char), 1, fin);
            fwrite(buf, sizeof(char), 1, fout);
        }
    }

    fclose(fin);
    fclose(fout);
}

void swapColor(string path) {
    int width, heigth, padding;
    const char *filedir = &path[0];
    char buf[100];
    string label = "_swap_color.";

    FILE *fin = fopen(filedir, "rb");
    FILE *fout = fopen(newName(path, label), "wb");

    // Mengambil tinggi dan lebar image
    fseek(fin, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fin);
    fread(&heigth, sizeof(int), 1, fin);

    // hitung padding yg dibutuhkan
    padding = (4 - ((width * 3) % 4)) % 4;

    // balik ke awal;
    rewind(fin);
    fread(buf, sizeof(char), 54, fin);
    fwrite(buf, sizeof(char), 54, fout);

    for (int y = 0; y < heigth; y++) {     // perulangan ke tinggi
        for (int x = 0; x < width; x++) {  // perulangan ke lebar
            fread(buf, sizeof(char), 3, fin);
            // Swap Color Red and Blue
            char tmp = buf[0];
            buf[0] = buf[2];
            buf[2] = tmp;
            fwrite(buf, sizeof(char), 3, fout);
        }
        for (int x = 0; x < padding; x++) {  // menambahkan padding
            fread(buf, sizeof(char), 1, fin);
            fwrite(buf, sizeof(char), 1, fout);
        }
    }

    fclose(fin);
    fclose(fout);
}

void increaseBrightness(string path) {
    int width, heigth, padding;
    const char *filedir = &path[0];
    char buf[100];
    string label = "_increase_brightness.";

    FILE *fin = fopen(filedir, "rb");
    FILE *fout = fopen(newName(path, label), "wb");

    // Mengambil tinggi dan lebar image
    fseek(fin, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fin);
    fread(&heigth, sizeof(int), 1, fin);

    // hitung padding yg dibutuhkan
    padding = (4 - ((width * 3) % 4)) % 4;

    // balik ke awal;
    rewind(fin);
    fread(buf, sizeof(char), 54, fin);
    fwrite(buf, sizeof(char), 54, fout);

    for (int y = 0; y < heigth; y++) {  // perulangan ke tinggi
        int white = 0;
        for (int x = 0; x < width; x++) {  // perulangan ke lebar
            fread(buf, sizeof(char), 3, fin);
            // Tambah Kecerahan Gambar
            char brightness = (buf[0] | buf[1] | buf[2]) / 3;
            buf[0] += brightness;
            buf[1] += brightness;
            buf[2] += brightness;
            fwrite(buf, sizeof(char), 3, fout);
        }
        for (int x = 0; x < padding; x++) {  // menambahkan padding
            fread(buf, sizeof(char), 1, fin);
            fwrite(buf, sizeof(char), 1, fout);
        }
    }

    fclose(fin);
    fclose(fout);
}