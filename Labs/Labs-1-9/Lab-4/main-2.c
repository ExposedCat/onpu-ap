#include <stdio.h>
#include <math.h>
#include <time.h>
void main() {
    int month, year;
    printf("Input month and year\n");
    scanf("%d %d", &month, &year);

    int alreadyBorn = 0;
    if (month <= 9) {
        alreadyBorn = 1;
    }
    int age = 2021 - year + alreadyBorn;
    switch (age) {
        case 0 ... 6: {
            printf("Kindergarten");
            break;
        }
        case 7 ... 17: {
            printf("School");
            break;
        }
        case 18 ... 22: {
            printf("Student");
            break;
        }
        default: {
            printf("Finished");
        }
    }

    printf("\n\n");
}