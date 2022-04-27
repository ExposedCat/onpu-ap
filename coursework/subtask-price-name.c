#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entity-queue.h"

void calc_price_by_name(struct Jewel_Queue* queue) {
    char name[50];
    printf("Input name: ");
    scanf("%s", &name);

    struct Jewel* p_jewel = queue->first;
    double total_price = 0;
    if (p_jewel != NULL) {
        while (p_jewel != NULL) {
            if (!strcmp(p_jewel->name, name)) {
                total_price += p_jewel->price;
            }
            p_jewel = p_jewel->next;
        }
    }
    if (total_price) {
        printf("Total price is %.2lf\n", total_price);
    } else {
        printf("Total price is 0.00 (no jewels found)\n");
    }
}