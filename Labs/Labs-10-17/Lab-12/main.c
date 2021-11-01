#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_words(char string[51]) {
    int count = 1;
    for (int i = 0; i < 50; ++i) {
        if (isspace(string[i])) {
            count++;
        }
    }
    return count;
}

int count_o(char word[51]) {
    int count = 0;
    for (int i = 0; i < 50; ++i) {
        if (word[i] == 'o' || word[i] == 'O') {
            count++;
        }
    }
    return count;
}

void replace_o_with_a(char string[51], char target_string[51]) {
    char new_string[51];
    for (int i = 0; i < 50; ++i) {
        switch (string[i]) {
            case 'o':
                new_string[i] = 'a';
                break;
            case 'O':
                new_string[i] = 'A';
                break;
            default:
                new_string[i] = string[i];
                break;
        }
    }
    strcpy(target_string, new_string);
}

void main() {
    char string[51];
    printf("Input string (max. 50 characters): ");
    scanf("%[^\n]%*c", string);

    int words_number = count_words(string);
    int o_number = count_o(string);
    char new_string[51];
    replace_o_with_a(string, new_string);

    printf("Words number: %d\n", words_number);
    printf("Number of \"O\": %d\n", o_number);
    printf("Replaced O with A: \"%s\"\n", new_string);

    printf("\n");
}