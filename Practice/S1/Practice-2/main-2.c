#include <stdio.h>

void main() {
    unsigned count = 0;
    int number;

    do {
        printf("Input number: ");
        scanf("%d", &number);
        if (number && number >= -10 && number <= 25) {
            count++;
        }
    } while (number);
    printf("Count: %d\n\n", count);
}