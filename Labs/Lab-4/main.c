#include <stdio.h>
#include <math.h>
void main() {
    char c;
    printf("Input character\n");
    scanf("%c", &c);

    printf("Symbol %c is ", c);
    switch (c) {
        case '0' ... '9': {
            printf("a number");
            break;
        }
        case 'A' ... 'Z': {
            printf("an uppercase letter");
            break;
        }
        case 'a' ... 'z': {
            printf("a lowercase letter");
            break;
        }
        default: {
            printf("something else");
        }
    }

    printf("\n\n");
}