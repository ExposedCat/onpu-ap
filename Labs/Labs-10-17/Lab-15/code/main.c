#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getBinary(int decimal) {
    char* binary = malloc(10);
    for (int i = 0; i < 10; ++i) {
        if (decimal > 0) {
            binary[9 - i] = decimal % 2 + 48;
            decimal /= 2;
        } else {
            binary[9 - i] = '0';
        }
    }
    return binary;
}

void main() {
    FILE* file_a = fopen("A.txt", "r");
    int a, b;
    fscanf(file_a, "A = %d\nB = %d", &a, &b);
    fclose(file_a);

    int y = (a + (3 * b) >> 1) << 4;

    FILE* file_b = fopen("gi-B", "w");
    fprintf(file_b, "Y = %d", y);
    fclose(file_b);
    printf("Result stored at gi-B file (\"gi-\" for git ignore)\n\n");

    int number = 124;
    printf("|----|---------|-----------|------|------|---------|\n");
    printf("| №  |  Number |    Cut    | Zero | Set  |  Invert |\n");
    printf("|----|---------|-----------|------|------|---------|\n");
    printf("| 17 |   %3d   |  3, 4, 5  | 1, 2 | 6, 7 |    5    |\n", number);
    printf("|----|---------|-----------|------|------|---------|\n\n");

    printf("|---------|------|------------|\n");
    printf("| Indices          9876543210 |\n");
    printf("|---------|------|------------|\n");
    printf("| Number  | %4d | %s |\n", number, getBinary(number));
    printf("|---------|------|------------|\n");
    int cut = (number >> 3) & ((1 << (6 - 3)) -1);
    printf("| Cut     | %4d | %s |\n", cut, getBinary(cut));
    printf("|---------|------|------------|\n");
    int zero = number & ~(1 << 1);
    zero &= ~(1 << 2);
    printf("| Zero    | %4d | %s |\n", zero, getBinary(zero));
    printf("|---------|------|------------|\n");
    int set = number | (1 << 6);
    set |= (1 << 7);
    printf("| Set     | %4d | %s |\n", set, getBinary(set));
    printf("|---------|------|------------|\n");
    int invert = number ^ (1 << 5);
    printf("| Invert  | %4d | %s |\n", invert, getBinary(invert));
    printf("|---------|------|------------|\n");

    printf("\n");
}