#include <math.h>
#include <stdio.h>
void main() {
    unsigned m, n;
    printf("Input m: ");
    scanf("%d", &m);
    printf("Input n: ");
    scanf("%d", &n);

    if (m == 1 && n == 1) {
        printf("( 0.00 )\n\n");
        return;
    }

    double matrix[m][n];
    const unsigned size = m * n / 2;
    double array[size];
    unsigned index = 0;

    printf("\nInput matrix %dx%d:\n", m, n);
    for (unsigned row = 0; row < m; ++row) {
        for (unsigned column = 0; column < n; ++column) {
            scanf("%lf", &matrix[row][column]);
            if ((row + column) % 2 != 0) {
                array[index] = matrix[row][column];
                index++;
            }
        }
    }

    for (unsigned i = 0; i < size - 1; ++i) {
        for (unsigned j = 0; j < size - i - 1; ++j) {
            if (array[j] < array[j + 1]) {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    index = 0;
    for (unsigned row = 0; row < m; ++row) {
        for (unsigned column = 0; column < n; ++column) {
            if ((row + column) % 2 == 0) {
                matrix[row][column] = 0;
            } else {
                matrix[row][column] = array[index];
                index++;
            }
        }
    }

    printf("\n");

    for (unsigned row = 0; row < m; ++row) {
        printf("( ");
        for (unsigned column = 0; column < n; ++column) {
            printf("%5.2lf ", matrix[row][column]);
        }
        printf(")\n");
    }

    printf("\n\n");
}