#include <iostream>
#include <cstdlib>
using namespace std;

main()
{
    // Membuat Matrik 1
    cout << "Buat Matrik Pertama" << endl;
    int m, n;

    cout << "Banyaknya Baris Pada Matrik ? : ";
    cin >> m;
    cout << "Banyaknya Kolom Pada Matrik ? : ";
    cin >> n;

    int mt1[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Masukkan Baris ke " << i + 1 << " Kolom ke " << j + 1 << ": ";
            cin >> mt1[i][j];
        }
    }
    system("CLS");

    cout << "Buat Matrik Pertama" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mt1[i][j] << "\t";
        }
    }

    system("Pause");
    system("CLS");

    // Membuat Matrik 2

    cout << "Buat Matrik Kedua" << endl;
    int a, b;

    cout << "Banyaknya Baris Pada Matrik ? : ";
    cin >> a;
    cout << "Banyaknya Kolom Pada Matrik ? : ";
    cin >> b;

    int mt2[a][b];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "Masukkan Baris ke " << i + 1 << " Kolom ke " << j + 1 << ": ";
            cin >> mt2[i][j];
        }
    }
    system("CLS");

    cout << "Buat Matrik Kedua" << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << mt2[i][j] << "\t";
        }
        cout << endl;
    }
    system("Pause");
    system("CLS");

    // Mengecek apakah jumlah kolom matrik 1 == jumlah baris matrik ke 2
    if (n == a)
    {
        cout << "Hasil Perkalian Matrik Tersebut adalah : " << endl;
        //Buat matrik baru untuk menampung hasil kali
        int result[m][b];

        // Kalikan Matrik 1 dan 2
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < b; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res = res + (mt1[i][k] * mt2[k][j]);
                }
                result[i][j] = res;
                res = 0;
            }
        }

        // tampilkan Hasil Kali
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cout << result[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Matrik Tidak Bisa Dikalikan !" << endl;
    }
}
