#include <stdio.h>

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

    printf("№  |  Number | Highlight | Zero | Set  | Invert\n");
    printf("17 |   124   |  3, 4, 5  | 1, 2 | 6, 7 | 5\n");
    printf("Number after bitwise magic: ");
    int number = 124;
    // IDK what is "highlighting" bits, there is no such operation.
    number = number & ~(1 << 1);
    number = number & ~(1 << 2);
    number = number | (1 << 6);
    number = number | (1 << 7);
    number = number ^ (1 << 5);
    printf("%d\n", number);

    printf("\n");
}