#include <stdio.h>
#include <math.h>
void main() {
    unsigned code;
    const unsigned minutes = 10;
    printf("Input city code: ");
    scanf("%d", &code);

    printf("Price for ");
    switch (code) {
        case 44: {
            printf("Kiev: %.2lf", minutes * 0.55);
            break;
        }
        case 32: {
            printf("Lviv: %.2lf", minutes * 0.45);
            break;
        }
        case 57: {
            printf("Kharkiv: %.2lf", minutes * 0.35);
            break;
        }
        case 56: {
            printf("Dnieper: %.2lf", minutes * 0.40);
            break;
        }
        default: {
            printf("Invalid code specified");
        }
    }

    printf(" uah/min\n\n");
}