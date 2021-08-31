#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> v;
    int size;
    cin >> size;
    int a;
    for (int i = 0; i < size; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    // khusus untuk vector bisa menggunakan for seperti ini
    for (auto i : v) {
        cout << i << " ";
    }
    return 0;
}
