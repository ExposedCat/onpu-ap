#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_vowel(char letter) {
    return letter == 'a' ||
           letter == 'e' ||
           letter == 'i' ||
           letter == 'o' ||
           letter == 'u' ||
           letter == 'y' ||
           letter == 'A' ||
           letter == 'E' ||
           letter == 'I' ||
           letter == 'O' ||
           letter == 'U' ||
           letter == 'Y';
}

int is_abcdef(char letter) {
    return letter == 'A' ||
           letter == 'B' ||
           letter == 'C' ||
           letter == 'D' ||
           letter == 'E' ||
           letter == 'F';
}

void main() {
    FILE *file_a = fopen("A", "wr");
    FILE *file_b = fopen("B", "wr");
    FILE *file_c = fopen("C", "wr");
    char data_a[51], data_b[51];

    printf("Input letters to file A (no spaces, no more then 50): ");
    scanf("%s%c", data_a);
    fprintf(file_a, "%s", data_a);
    printf("Input letters to file B (no spaces, no more then 50): ");
    scanf("%s%c", data_b);
    fprintf(file_b, "%s", data_b);

    for (int i = 0; i < 50; ++i) {
        if (is_vowel(data_a[i])) {
            fprintf(file_c, "%c", data_a[i]);
        }
        if (is_vowel(data_b[i])) {
            fprintf(file_c, "%c", data_b[i]);
        }
    }

    for (int i = 0; i < 50; ++i) {
        if (is_abcdef(data_b[i])) {
            fprintf(file_a, "%c", data_b[i]);
        }
    }
}