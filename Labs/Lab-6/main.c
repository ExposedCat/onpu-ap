#include <math.h>
#include <stdio.h>

double n(unsigned i) {
    return (1 / pow(2, i));
}

void resolve(double input, unsigned task) {
    double number = input + 1;

    unsigned small_number_index = 0;
    double sum = 0;

    printf("\n┌────────────────────────┐\n", number);
    for (
        unsigned i = 1;
        (task == 0 && number >= input) ||
        (task == 1 && (fabs(n(i - 1) - n(i)) >= input || i == 1));
        ++i
    ) {
        number = n(i);
        sum += number;
        small_number_index = i;
        printf("│ %5d  %6.10lf    │\n", i, number);
    }
    printf("└────────────────────────┘\n");

    small_number_index++;
    printf("\n┌────────────────────────────────────────┐\n");
    if (task == 0) {
        printf("│            Sum: %6.10lf           │\n", sum);
    }
    printf("│  First number:      %3d: %6.10lf  │", n(small_number_index), small_number_index);
    printf("\n└────────────────────────────────────────┘\n");
}

void main() {
    double a;
    scanf("%lf", &a);
    resolve(a, 0);
    double e;
    scanf("%lf", &e);
    resolve(e, 1);
}