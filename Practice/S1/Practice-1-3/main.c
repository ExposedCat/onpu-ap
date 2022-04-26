// Arrays size
#define N 5

#include <stdio.h>
#include <stdlib.h>

// Calculates sum of array elements are multiple of number
int get_sum_of_multiples(int* array, int number) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int value = *(array + i);
        if (!(value % number)) {
            sum += value;
        }
    }
    return sum;
}

int main() {
    // Init arrays
    int* array1 = malloc(sizeof(int) * N);
    int array2[N] = {2, 5, 7, 14, 9};

    // Input first array
    printf("Input first array\n> ");
    for (int i = 0; i < N; ++i) {
        scanf("%d", array1 + i);
    }

    // Calculate sum of multiples of 6 from 1st array
    int sum1 = get_sum_of_multiples(array1, 6);

    // Calculate sum of multiples of 7 from 2st array
    int sum2 = get_sum_of_multiples(array2, 7);

    // Output results
    printf("Sum of multiplies of 6 from 1st array is %d\n", sum1);
    printf("Sum of multiplies of 7 from 2st array is %d\n", sum2);

    printf("\n\n");
    return 0;
}