#include <stdio.h>
void main() {
    unsigned rows = 15;
    unsigned columns;
    printf("Input columns number: ");
    scanf("%d", &columns);

    double matrix[rows][columns];
    const unsigned size = rows * columns / 2;
    double array[size];
    unsigned index = 0;

    printf("\nInput matrix %dx%d:\n", rows, columns);
    for (unsigned row = 0; row < rows; ++row) {
        for (unsigned column = 0; column < columns; ++column) {
            scanf("%lf", &matrix[row][column]);
        }
    }

    for (unsigned row = 0; row < 3; ++row) {
        // for instead of assignment because C is a piece of shit
        for (unsigned column = 0; column < columns; ++column) {
            double temp = matrix[rows - 3 + row][column];
            matrix[rows - 3 + row][column] = matrix[row][column];
            matrix[row][column] = temp;
        }
    }

    printf("\n");

    for (unsigned row = 0; row < rows; ++row) {
        printf("( ");
        for (unsigned column = 0; column < columns; ++column) {
            printf("%5.2lf ", matrix[row][column]);
        }
        printf(")\n");
    }

    printf("\n\n");
}