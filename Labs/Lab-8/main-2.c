#include <math.h>
#include <stdio.h>

unsigned long factorial(unsigned a) {
    if (a == 0) {
        return 1;
    }
    return a * factorial(a - 1);
}

void main() {
    unsigned n;
    double sum = 0;

    printf("┌─────────────┐\n");
    printf("│  N = ");
    scanf("%d", &n);
    printf("└─────────────┘\n");

    for (int k = 1; k <= n; ++k) {  // Not unsigned int, because C is a piece of shit.
        if (k == 3) {
            continue;
        }
        double q = pow(k - 3, k - 5) * (k + 7) / factorial(k);
        sum += q;
    }

    printf("┌─────────────┐\n");
    printf("│  Sum = %5.2lf│\n", sum);
    printf("└─────────────┘");

    printf("\n");
}