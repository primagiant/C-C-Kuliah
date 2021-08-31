#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, nums;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums;
        v.push_back(nums);
    }

    int del;
    cin >> del;
    v.erase(v.begin() + (del - 1));

    int start, end;
    cin >> start >> end;
    v.erase(v.begin() + (start - 1), v.begin() + (end - 1));

    cout << v.size() << endl;
    for (auto i : v) cout << i << " ";

    return 0;
}