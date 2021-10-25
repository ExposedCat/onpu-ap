#include <math.h>
#include <stdio.h>

double n(unsigned i) {
    return (1 / pow(i, 3));
}

void main() {
    double a;
    scanf("%lf", &a);
    double number = a;

    unsigned small_number_index = 0;
    double sum = 0;

    printf("\n┌────────────────────────┐\n", number);
    for (
        unsigned i = 1;
        number >= a;
        ++i) {
        number = n(i);
        sum += number;
        small_number_index = i;
        printf("│ %5d  %6.10lf    │\n", i, number);
    }
    printf("└────────────────────────┘\n");
    small_number_index++;
    printf("\n┌────────────────────────────────────────┐\n");
    printf("│            Sum: %6.10lf           │\n", sum);
    printf("│  First number:      %3d: %6.10lf  │", n(small_number_index), small_number_index);
    printf("\n└────────────────────────────────────────┘\n");
}