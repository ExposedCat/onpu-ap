#include <stdio.h>
#include <stdlib.h>

#include "entity-queue.h"

void print_queue_in_price_range(struct Jewel_Queue* queue) {
    int min_price;
    printf("Input minimal price: ");
    scanf("%d", &min_price);
    int max_price;
    printf("Input maximal price: ");
    scanf("%d", &max_price);

    struct Jewel* p_jewel = queue->first;
    if (p_jewel == NULL) {
        printf("Jewel queue is empty\n");
    } else {
        while (p_jewel != NULL) {
            if (p_jewel->price >= min_price && p_jewel->price <= max_price) {
                print_jewel(p_jewel);
            }
            p_jewel = p_jewel->next;
        }
    }
}