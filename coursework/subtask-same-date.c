#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entity-queue.h"

void print_jewels_with_same_date(struct Jewel_Queue* queue) {
    struct Jewel* p_jewel = queue->first;
    if (p_jewel == NULL) {
        printf("Jewel queue is empty\n");
    } else {
        int printed = 0;
        while (p_jewel != NULL) {
            struct Jewel* p_jewel_2 = queue->first;
            while (p_jewel_2 != NULL) {
                if (p_jewel_2 != p_jewel && !strcmp(p_jewel_2->date, p_jewel->date)) {
                    print_jewel(p_jewel_2);
                    printed = 1;
                }
                p_jewel_2 = p_jewel_2->next;
            }
            p_jewel = p_jewel->next;
        }
        if (!printed) {
            printf("No jewels with same date found\n");
        }
    }
}