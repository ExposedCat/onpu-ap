#include <stdio.h>
#include <stdlib.h>

#include "entity-queue.h"

void print_queue_in_price_range(struct Jewel_Queue* queue) {
    double min_price;
    printf("Input minimal price: ");
    scanf("%lf", &min_price);
    double max_price;
    printf("Input maximal price: ");
    scanf("%lf", &max_price);

    struct Jewel* p_jewel = queue->first;
    if (p_jewel == NULL) {
        printf("Jewel queue is empty\n");
    } else {
        int printed = 0;
        while (p_jewel != NULL) {
            if (p_jewel->price >= min_price && p_jewel->price <= max_price) {
                print_jewel(p_jewel);
                printed = 1;
            }
            p_jewel = p_jewel->next;
        }
        if (!printed) {
            printf("No jewels found\n");
        }
    }
}