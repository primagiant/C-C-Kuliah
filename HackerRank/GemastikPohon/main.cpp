#include <iostream>
#include <set>
using namespace std;

int main() {
    // coordinat pertama
    int n, x1, y1, x2, y2;
    float m;
    cin >> n >> x1 >> y1;

    int count;
    set<float> sh;
    set<float> sl;
    // coordiant kedua akan ditampung dalam vector
    for (int i = 0; i < n; i++) {
        cin >> x2 >> y2;
        m = (float)(y2 - y1) / (float)(x2 - x1);
        if (x2 > x1 || y2 > y1) {
            sh.insert(m);
        } else {
            sl.insert(m);
        }
    }

    count = sh.size() + sl.size();

    cout << "Pohon Yang dapat Dilihat : ";
    cout << count << endl;

    return 0;
}
