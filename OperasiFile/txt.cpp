#include <cstdio>
#include <string>

int main(int argc, char const* argv[]) {
    FILE* f;
    char buffer[100];

    // Read Text
    f = fopen("D:\\Documents\\Program\\C++\\OperasiFile\\txt.txt", "r");

    while (fgets(buffer, 99, f)) {
        puts(buffer);
    }

    // Append Text
    f = fopen("D:\\Documents\\Program\\C++\\OperasiFile\\txt.txt", "a");
    fputs("\n", f);
    fputs("Topi Saya Bundar\n", f);
    fputs("Bundar Topi Saya\n", f);

    // Write Text
    f = fopen("D:\\Documents\\Program\\C++\\OperasiFile\\txt.txt", "w");
    fputs("\n", f);
    fputs("Topi Saya Bundar\n", f);
    fputs("Bundar Topi Saya\n", f);

    fclose(f);

    return 0;
}
