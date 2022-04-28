#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entity-queue.h"
#include "subtask-add.h"
#include "subtask-edit-existing.h"
#include "subtask-price-name.h"
#include "subtask-price-range.h"
#include "subtask-same-date.h"
#include "subtask-search-criteria.h"
#include "subtask-sort-price.h"
#include "util-ui.h"

int field_equal_to(struct Jewel* jewel, int field, char* string, int number) {
    switch (field) {
        case 1: {
            return !strcmp(jewel->name, string);
        }
        case 2: {
            return !strcmp(jewel->type, string);
        }
        case 3: {
            return jewel->weight == number;
        }
        case 4: {
            return jewel->number == number;
        }
        case 5: {
            return !strcmp(jewel->stone_name, string);
        }
        case 6: {
            return jewel->carat_weight == number;
        }
        case 7: {
            return jewel->price == number;
        }
        case 8: {
            return !strcmp(jewel->date, string);
        }
    }
}

int input_field_data(int field, char* string, int* number) {
    int success = 1;
    printf("To perform search, input ");
    switch (field) {
        case 1: {
            printf("name: ");
            scanf("%s", string);
            break;
        }
        case 2: {
            printf("type: ");
            scanf("%s", string);
            break;
        }
        case 3: {
            printf("weight: ");
            success = scanf("%d", number) && success;
            break;
        }
        case 4: {
            printf("number of stones: ");
            success = scanf("%d", number) && success;
            break;
        }
        case 5: {
            printf("stone name: ");
            scanf("%s", string);
            break;
        }
        case 6: {
            printf("carat weight: ");
            success = scanf("%d", number) && success;
            break;
        }
        case 7: {
            printf("price: ");
            success = scanf("%d", number) && success;
            break;
        }
        case 8: {
            printf("date: ");
            scanf("%s", string);
            break;
        }
    }
    return !success;
}

int process_field_input(struct Jewel* jewel, int input) {
    int success = 1;
    printf("Input new ");
    switch (input) {
        case 1: {
            printf("name: ");
            success = scanf("%s", jewel->name) && success;
            break;
        }
        case 2: {
            printf("type: ");
            success = scanf("%s", jewel->type) && success;
            break;
        }
        case 3: {
            printf("weight: ");
            success = scanf("%d", &jewel->weight) && success;
            break;
        }
        case 4: {
            printf("number of stones: ");
            success = scanf("%d", &jewel->number) && success;
            break;
        }
        case 5: {
            printf("stone name: ");
            success = scanf("%s", jewel->stone_name) && success;
            break;
        }
        case 6: {
            printf("carat weight: ");
            success = scanf("%d", &jewel->carat_weight) && success;
            break;
        }
        case 7: {
            printf("price: ");
            success = scanf("%d", &jewel->price) && success;
            break;
        }
        case 8: {
            printf("date: ");
            success = scanf("%s", jewel->date) && success;
            break;
        }
    }
    return !success;
}

int process_input(struct Jewel_Queue* jewels, int input) {
    int error = 0;
    switch (input) {
        case 1: {
            add_jewel(jewels);
            break;
        }
        case 2: {
            remove_first_from_queue(jewels);
            break;
        }
        case 3: {
            error = edit_existing(jewels);
            break;
        }
        case 4: {
            print_queue(jewels);
            break;
        }
        case 5: {
            print_queue_in_price_range(jewels);
            break;
        }
        case 6: {
            search_by_criteria(jewels);
            break;
        }
        case 7: {
            calc_price_by_name(jewels);
            break;
        }
        case 8: {
            print_jewels_with_same_date(jewels);
            break;
        }
        case 9: {
            sort_by_price(jewels);
            break;
        }

        default: {
            error = 1;
        }
    }
    pause();
    printf("Task finished with exit code %d\n", error);
    return error;
}