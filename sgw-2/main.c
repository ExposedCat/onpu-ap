#include <stdio.h>
#include <stdlib.h>

int input_array(int n, double array[n]) {
    printf("Input array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d) ", i + 1);
        const int valid = scanf("%lf", array + i);
        if (!valid) {
            return 1;
        }
    }
    return 0;
}

double sum(double a, double b) {
    return a + b;
}

double get_max_pair(int n, double array[n], int* index) {
    double max;
    for (int i = 0; i < n / 2; ++i) {
        double pair_sum = sum(array[i], array[n - i - 1]);
        if (i == 0 || pair_sum > max) {
            max = pair_sum;
            *index = i;
        }
    }
    return max;
}

int write_to_file(char* text, char* filename) {
    FILE* file = fopen(filename, "w+");
    if (file == NULL) {
        return 1;
    }
    fprintf(file, text);
    fclose(file);
    return 0;
}

int main() {
    const int n = 10;
    double* array = malloc(sizeof(double) * n);
    const int error = input_array(n, array);
    if (error) {
        printf("Invalid input: entered not real number");
        return 1;
    }
    int max_index = -1;
    const double pair_sum = get_max_pair(n, array, &max_index);
    if (max_index != -1) {
        char* text = malloc(sizeof(char) * 300);
        sprintf(
            text,
            "Max pair is (%d; %d) with sum %.3lf\n",
            max_index + 1,
            n - max_index,
            pair_sum);
        const int error = write_to_file(text, "output.txt");
        if (error) {
            printf("Can not open file. Please check rights to do so\n");
            return 1;
        }
        printf("Result written to file «output.txt» in project root\n");
    } else {
        printf("Error: max pair not found\n");
        return 1;
    }

    printf("\n\n");
    return 0;
}