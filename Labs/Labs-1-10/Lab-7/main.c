#include <math.h>
#include <stdio.h>
void main() {
    printf("┌──────┬──────┐\n");
    printf("│  num │ sqrt │\n");
    for (unsigned number = 1; number <= 300; ++number) {
        double roots_sum;
        switch (number) {
            case 1 ... 9: {
                roots_sum = sqrt(number);
                break;
            }
            case 10 ... 99: {
                unsigned last = number % 10;
                unsigned first = number / 10;
                roots_sum = sqrt(first) + sqrt(last);
                break;
            }
            case 100 ... 300: {
                unsigned last = number % 10;
                unsigned middle = number / 10 % 10;
                unsigned first = number / 100;
                roots_sum = sqrt(first) + sqrt(middle) + sqrt(last);
                break;
            }
        }
        if (roots_sum == (int)roots_sum) {
            printf("├──────┼──────┤\n");
            printf("│  %3d │%6.2lf│\n", number, roots_sum);
        }
    }

    printf("└──────┴──────┘\n");
    printf("\n\n");
}
