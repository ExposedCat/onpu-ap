#include <stdio.h>
#include <stdlib.h>
#define N 4

void input_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        printf("> ");
        for (int j = 0; j < N; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int get_min(int matrix[N][N]) {
    int min = 9999;
    for (int i = 1; i < N; ++i) {
        for (int j = N - 1; j >= N - i; --j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int get_max(int matrix[N][N]) {
    int max = -9999;
    for (int i = 1; i < N; ++i) {
        for (int j = N - 1; j >= N - i; --j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

double get_average(int a, int b) {
    return (a + b) / 2;
}

int main() {
    int matrix[N][N];
    printf("Input matrix:\n");
    input_matrix(matrix);
    int min = get_min(matrix);
    printf("Min = %d\n", min);
    int max = get_max(matrix);
    printf("Max = %d\n", max);
    double average = get_average(min, max);
    printf("Average = %.3lf\n", average);

    printf("\n\n");
    return 0;
}