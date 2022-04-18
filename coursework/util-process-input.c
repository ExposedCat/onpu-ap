#include <stdio.h>
#include <stdlib.h>

#include "entity-queue.h"
#include "subtask-add.h"
#include "subtask-price-name.h"
#include "subtask-price-range.h"
#include "subtask-same-date.h"
#include "util-ui.h"

int process_input(struct Jewel_Queue* jewels, int input) {
    switch (input) {
        case 1:
            add_jewel(jewels);
            printf("Jewel added successfully\n");
            break;
        case 2:
            remove_first_from_queue(jewels);
            printf("First jewel in queue removed successfully\n");
            break;
        case 3:
            // Edit existing jewel
            break;
        case 4:
            print_queue(jewels);
            printf("All jewels printed successfully\n");
            break;
        case 5:
            print_queue_in_price_range(jewels);
            printf("All jewels in price range printed successfully\n");
            break;
        case 6:
            // Search by criteria
            break;
        case 7:
            calc_price_by_name(jewels);
            printf("Total price printed successfully\n");
            break;
        case 8:
            print_jewels_with_same_date(jewels);
            printf("All jewels with same date printed successfully\n");
            break;
        case 9:
            // Sort by price
            break;

        default:
            return 1;
    }
    pause();
    return 0;
}