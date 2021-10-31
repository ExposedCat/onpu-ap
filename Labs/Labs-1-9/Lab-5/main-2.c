#include <math.h>
#include <stdio.h>
void main() {
    int number;
    double sum = 0;
    unsigned count = 0;

    do {
        printf("Input number (0 to stop): ");
        scanf("%d", &number);
        if (number != 0) {
            count++;
            sum += number;
        }
    } while (number != 0);

    printf("Average: %.2lf", sum / count);
    printf("\n\n");
}