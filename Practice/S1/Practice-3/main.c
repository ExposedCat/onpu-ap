#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_integer(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void main() {
    // Here some dark magic again
    // because of C's awfulness
    srand(time(0));

    unsigned questions_number;
    printf("Input number of questions: ");
    scanf("%d", &questions_number);

    printf("Test \"Subtraction\" (%d questions):\n", questions_number);
    unsigned points = 0;
    for (unsigned i = 0; i < questions_number; ++i) {
        int first = random_integer(-99, 99);
        int second = random_integer(-99, 99);
        printf("%d) %d - %d = ", i + 1, first, second);
        int result = 0;
        scanf("%d", &result);
        if (result == first - second) {
            points++;
        }
    }

    int percent = (double)points / questions_number * 100;
    printf("\nCorrect answers: %d (%d%)\n\n", points, percent);
}