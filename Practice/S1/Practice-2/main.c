#include <math.h>
#include <stdio.h>

int ask_question(
    char* question,
    char* answer1, char* answer2, char* answer3,
    unsigned true_answer) {
    printf("%s?\nType number of answer to answer:\n", question);
    printf("1. %s\n", answer1);
    printf("2. %s\n", answer2);
    printf("3. %s\n", answer3);
    unsigned answer;
    int valid_input = scanf("%d", &answer);
    if (!valid_input || (answer != 1 && answer != 2 && answer != 3)) {
        return 0;
    } else {
        return answer == true_answer;
    }
}

void main() {
    unsigned sum = 0;
    sum += ask_question(
        "Which of these U.S. states does NOT border Canada",
        "Maine", "Alaska", "Indiana*",
        3
    );
    sum += ask_question(
        "Which of these countries was NOT a part of the Soviet Union",
        "Ukraine", "Poland*", "Belarus",
        2
    );
    sum += ask_question(
        "Which of these cities is NOT a national capital",
        "Sydney*", "Cairo", "Prague",
        1
    );
    sum += ask_question(
        "Which of these cities DOESN'T border the Mediterranean Sea",
        "Lisbon*", "Monaco", "Alexandria",
        1
    );
    sum += ask_question(
        "Which of these countries was NEVER part of the British Empire",
        "Kenya", "Ireland", "Thailand*",
        3
    );
    sum += ask_question(
        " Which one of these cities is NOT in the Southern Hemisphere",
        "Brasilia", "Colombo*", "Brisbane",
        2
    );
    printf("Your points: %d\n\n", sum);
}