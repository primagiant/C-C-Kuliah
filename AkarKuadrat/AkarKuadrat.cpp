#include <cmath>
#include <iostream>

using namespace std;

int main() {
    // deklarasi variable
    int a, b, c, D;
    float x1, x2;

    cin >> a >> b >> c;

    // Rumus Diskriminan
    D = (b * b) - (4 * a * c);

    // Rumus abc
    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
    } else if (D == 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = x1;
    } else {
        exit(0);
    }

    cout << x1 << " " << x2 << endl;

    return 0;
}