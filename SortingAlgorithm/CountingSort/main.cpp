#include <iostream>
#include <vector>
using namespace std;

const int maxRange = 9;

void countSort(vector<int> nums) {
    vector<int> store;
    for (int i = 0; i <= maxRange; ++i) {  // isi semua data pada store dengan 0
        store.push_back(0);
    }

    for (int i = 0; i < nums.size(); ++i) {  // menghitung jumlah item yang sama
        store[nums[i]]++;
    }

    for (int i = 1; i < store.size(); ++i) {  // menjumlahkan count index tertentu dengan index sebelum index tersebut
        store[i] += store[i - 1];
    }

    int output[nums.size()];                 // saat menggunakan vector malah ngebug
    for (int i = 0; i < nums.size(); ++i) {  // meletakkan item ketempat yang benar
        output[store[nums[i]] - 1] = nums[i];
        store[nums[i]]--;  // kurangi count
    }

    for (int i = 0; i < nums.size(); i++) {  // print hasil sorting
        cout << output[i] << " ";
    }
}

int main(int argc, char const *argv[]) {
    vector<int> unsorted = {1, 4, 1, 2, 7, 5, 2};
    countSort(unsorted);

    return 0;
}
