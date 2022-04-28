#include "util-ui.h"

#include <stdio.h>
#include <stdlib.h>

void pause() {
    printf(">> Press RETURN to continue <<");
    getchar();
    getchar();  // Burn in hell whoever invented all these crappy i/o functions in C!
}

void clear() {
    printf("\033[H\033[J");
}

int open_fields_menu(char* action) {
    clear();
    printf(
        "1. Name\n\
2. Type\n\
3. Weight\n\
4. Number of stones\n\
5. Stone name\n\
6. Carat weight\n\
7. Price\n\
8. Date\n\
Input number to %s → ", action);

    int selected;
    int is_number = scanf("%d", &selected);
    if (!is_number || selected < 1 || selected > 8) {
        printf("\n\nError: input must be an integer [1-8]. Exiting..\n");
        return 10;
    }
    return selected;
}

int open_menu() {
    clear();
    printf(
        "1. Add jewel to queue\n\
2. Remove first jewel from queue\n\
3. Edit existing jewel\n\
4. Show all jewels\n\
5. Search jewels by price range\n\
6. Search jewels by criteria\n\
7. Calculate total price by jewel name\n\
8. Find all with same date\n\
9. Sort by price\n\
10. Quit\n\
Input number to run task → ");

    int selected;
    int is_number = scanf("%d", &selected);
    if (!is_number || selected < 1 || selected > 10) {
        printf("\n\nError: input must be an integer [1-10]. Exiting..\n");
        return 10;
    }
    return selected;
}