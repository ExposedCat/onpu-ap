#include <stdio.h>

void main() {
    printf("Input 12 values: ");
    double values[12];
    for(int i = 0; i < 12; ++i) {
        scanf("%lf", &values[i]);
    }
    int pack_size = 3;
    for (int i = 0; i <= 12 - pack_size; i += 3) {
        double sum = 0;
        for (int offset = 0; offset < pack_size; ++offset) {
            sum += values[i + offset];
        }
        double average = sum / pack_size;
        printf("Quarterly average: %.3lf\n", average);
    }

    printf("\n");
}