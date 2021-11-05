#include <ctype.h>
// #include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char myString[101], text[901] = "";
    // setlocale(LC_ALL, "rus");
    printf("Введите текст: ");
    scanf("%[^\n]%*c", myString);

    int offset = 0;
    for (int i = 0; i < strlen(myString); i++) {
        char character = myString[i];
        if (character >= '0' && character <= '9') {
            for (int j = 0; j < (int)(character - '0'); j++) {
                text[i + offset] = '_';
                offset++;
            }
        } else {
            text[i + offset] = character;
        }
    }

    printf("_____\n");
    printf("\"%s\"\n\n", text);
    return 0;
}