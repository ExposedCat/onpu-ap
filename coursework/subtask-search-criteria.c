#include <stdio.h>
#include <stdlib.h>

#include "entity-queue.h"
#include "util-process-input.h"
#include "util-ui.h"

int search_by_criteria(struct Jewel_Queue* queue) {
    struct Jewel* p_jewel = queue->first;
    if (p_jewel == NULL) {
        printf("Jewel queue is empty\n");
        return 1;
    } else {
        const int field = open_fields_menu("choose field to search by");
        char string[101];
        int number;
        const int error = input_field_data(field, string, &number);
        if (error) {
            printf("Invalid input\n");
            return 1;
        }
        int printed = 0;
         while (p_jewel != NULL) {
            if (field_equal_to(p_jewel, field, string, number)) {
                print_jewel(p_jewel);
                printed = 1;
            }
            p_jewel = p_jewel->next;
        }
        if (!printed) {
            printf("No jewels found\n");
        }
        return 0;
    }
}