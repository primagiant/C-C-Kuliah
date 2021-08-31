#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> v;
    int N, X, Q, Y;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X;
        v.push_back(X);
    }
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> Y;
        vector<int>::iterator low;
        low = lower_bound(v.begin(), v.end(), Y);

        if (v[low - v.begin()] == Y) {
            cout << "Yes " << low - v.begin() + 1 << endl;
        } else {
            cout << "No " << low - v.begin() + 1 << endl;
        }
    }

    return 0;
}
