#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    const int size = 6;
    int array[size][size];
    printf("Input array elements:\n");
    printf("    ");
    for (int i = 1; i <= size; ++i) {
        printf("%d ", i);
    }
    printf("\n   ———————————\n");
    for (int i = 0; i < size; ++i) {
        printf("%d | ", i + 1);
        for (int j = 0; j < size; ++j) {
            scanf("%d", &array[i][j]);
        }
    }

    int target_i;
    printf("Input i: ");
    scanf("%d", &target_i);
    int target_j;
    printf("Input j: ");
    scanf("%d", &target_j);
    int product = 1;
    for (int i = 0; i < size; ++i) {
        product *= array[target_i - 1][i];
    }
    for (int i = 0; i < size; ++i) {
        product *= array[i][target_j - 1];
    }
    printf("Product = %d", product);

    for (int j = 0; j < size; ++j) {
        for (int i = size - 1; i != size - 1 - j; --i) {
            array[i][j] = 0;
        }
    }

    printf("    ");
    for (int i = 1; i <= size; ++i) {
        printf("%d ", i);
    }
    printf("\n   ———————————\n");
    for (int i = 0; i < size; ++i) {
        printf("%d | ", i + 1);
        for (int j = 0; j < size; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}