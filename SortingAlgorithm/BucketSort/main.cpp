#include <algorithm>  // sort
#include <iostream>   // input output
#include <vector>     // vector
using namespace std;

void bucketSort(float arr[], int n) {
    vector<float> bucket[n];  // membuat sebuah bucket kosong untuk menampung nilai

    for (int i = 0; i < n; i++) {  // memasukkan item pada array ke bucket
        int bucketIndex = n * arr[i];
        bucket[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {  // mengurutkan item pada setiap index
        sort(bucket[i].begin(), bucket[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {  // Memasukkan nilai yang sudah terurut kedalam array
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[index++] = bucket[i][j];
        }
    }

    cout << "Hasil : \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    float arr[] = {0.93, 0.39, 0.95, 0.12, 0.73, 0.18, 0.32};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    return 0;
}
