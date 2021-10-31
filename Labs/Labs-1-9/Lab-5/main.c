#include <math.h>
#include <stdio.h>
void main() {
    const double from = 2;
    const double to = 315;
    const double step = 13;
    double a;
    printf("Input a: ");
    scanf("%lf", &a);

    for (double x = from; x <= to; x += step) {
        if (x == from) {
            printf("\n┌────────┬────────┐\n");
        } else {
            printf("\n├────────┼────────┤\n");
        }
        printf("│ %6.2lf │ ", x);
        double numerator = a + pow(x, 3);
        if (numerator >= 0 && a != x) {
            double f = sqrt(numerator) / (a - x) + pow(x, 1.0 / 3);
            printf("%6.2lf │", f);
        } else {
            printf("   ∅   │");
        }
    }

    printf("\n└────────┴────────┘\n");
}
