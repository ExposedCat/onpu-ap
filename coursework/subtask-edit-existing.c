#include <stdio.h>
#include <stdlib.h>

#include "entity-queue.h"
#include "util-process-input.h"
#include "util-ui.h"

int edit_existing(struct Jewel_Queue* queue) {
    int number;
    printf("Input number of jewel to edit: ");
    const int valid = scanf("%d", &number);
    if (!valid) {
        printf("Invalid input\n");
        return 1;
    }

    struct Jewel* p_jewel = queue->first;
    if (p_jewel == NULL) {
        printf("Jewel not found\n");
        return 1;
    } else {
        for (int i = 0; i < number; ++i) {
            if (i == number - 1) {
                const int field = open_fields_menu("choose filed to edit");
                const int error = process_field_input(p_jewel, field);
                return error;
            }
            p_jewel = p_jewel->next;
            if (p_jewel == NULL) {
                printf("Jewel not found\n");
                return 0;
            }
        }
    }
}