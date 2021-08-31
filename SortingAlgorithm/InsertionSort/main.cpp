#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> nums) {
    int i, key, j;
    for (i = 1; i < nums.size(); i++) {  // membagi list menjadi dua yang terurut dengan yang belum terurut
        key = nums[i];
        j = i - 1;

        while (j >= 0 && nums[j] > key) {  // selema key lebih besar dari items dalam index tertentu shift right item tersebut
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
    return nums;
}

int main() {  // menjalankan fungsi sorting
    vector<int> unsorted = {4, 5, 1, 6, 3, 2, 9, 7};

    vector<int> sorted = insertionSort(unsorted);
    for (auto i : sorted) {
        cout << i << " ";
    }

    return 0;
}