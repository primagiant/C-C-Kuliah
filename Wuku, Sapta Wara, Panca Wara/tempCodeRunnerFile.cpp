if (valid_input) {
        int selisihHr = selisihHari(tgl, bln, tahun);
        //harus dimulai dari 1 january 1899
        string saptaWaraList[7] = {"Redite", "Soma", "Anggara", "Budha", "Wrespati", "Sukra", "Saniscara"},
               pancaWaraList[5] = {"Paing",
                                   "Pon",
                                   "Wage",
                                   "Kliwon",
                                   "Umanis"},
               wukuList[30] = {"Matal",
                               "Uye",
                               "Menail",
                               "Prangbakat",
                               "Bala",
                               "Ugu",
                               "Wayang",
                               "Kelawu",
                               "Dukut",
                               "Watugunung",
                               "Sinta",
                               "Landep",
                               "Ukir",
                               "Kulantir",
                               "Tolu",
                               "Gumbreg",
                               "Wariga",
                               "Warigadean",
                               "Julungwangi",
                               "Sungsang",
                               "Dungulan"
                               "Kuningan",
                               "Langkir",
                               "Medangsia",
                               "Pujut",
                               "Pahang",
                               "Krulut",
                               "Merakih",
                               "Tambir",
                               "Medangkungan"};

        string saptawara, pancawara, wuku;
        int hasilHr = selisihHr % 7;
        saptawara = saptaWaraList[hasilHr];

        hasilHr = selisihHr % 5;
        pancawara = pancaWaraList[hasilHr];

        hasilHr = (selisihHr / 7) % 30;
        wuku = wukuList[hasilHr];

        cout << "\nHasilnya :" << endl;
        cout << "Saptawara \t: " << saptawara << endl
             << "Pancawara \t: " << pancawara << endl
             << "Wuku \t\t: " << wuku << endl;
    } else {
        cout << "INPUT TIDAK VALID" << endl
             << "hari di input seperti contoh : 1 january 2000" << endl
             << "hari yang di input tidak boleh sebelum 1 january 1899";
    }