
#include <math.h>
#include <stdio.h>

int main() {
    // deklarasi variable
    int a, b, c, D;
    float x1, x2;

    scanf("%i %i %i", &a, &b, &c);

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
        return 0;
    }

    printf("%.2f %.2f", x1, x2);

    return 0;
}