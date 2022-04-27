#include <stdio.h>
#include <stdlib.h>

#include "entity-queue.h"
#include "subtask-add.h"
#include "subtask-edit-existing.h"
#include "subtask-price-name.h"
#include "subtask-price-range.h"
#include "subtask-same-date.h"
#include "subtask-sort-price.h"
#include "util-ui.h"

int process_field_input(struct Jewel* jewel, int input) {
    int success = 1;
    printf("Input new ");
    switch (input) {
        case 1:
            printf("name: ");
            success = scanf("%s", jewel->name) && success;
            break;
        case 2:
            printf("type: ");
            success = scanf("%s", jewel->type) && success;
            break;
        case 3:
            printf("weight: ");
            success = scanf("%d", &jewel->weight) && success;
            break;
        case 4:
            printf("number of stones: ");
            success = scanf("%d", &jewel->number) && success;
            break;
        case 5:
            printf("stone name: ");
            success = scanf("%s", jewel->stone_name) && success;
            break;
        case 6:
            printf("carat weight: ");
            success = scanf("%d", &jewel->carat_weight) && success;
            break;
        case 7:
            printf("price: ");
            success = scanf("%d", &jewel->price) && success;
            break;
        case 8:
            printf("date: ");
            success = scanf("%s", jewel->date) && success;
            break;
    }
    return !success;
}

int process_input(struct Jewel_Queue* jewels, int input) {
    int error = 0;
    switch (input) {
        case 1:
            add_jewel(jewels);
            break;
        case 2:
            remove_first_from_queue(jewels);
            break;
        case 3:
            error = edit_existing(jewels);
            break;
        case 4:
            print_queue(jewels);
            break;
        case 5:
            print_queue_in_price_range(jewels);
            break;
        case 6:
            // Search by criteria
            break;
        case 7:
            calc_price_by_name(jewels);
            break;
        case 8:
            print_jewels_with_same_date(jewels);
            break;
        case 9:
            sort_by_price(jewels);
            break;

        default:
            return error = 1;
    }
    pause();
    printf("Task finished with exit code %d\n", error);
    return error;
}