#include "queue.h"

#include <stdio.h>

void init_queue(struct Jewel_Queue* queue) {
    queue->first = NULL;
    queue->last = NULL;
}

void add_to_queue(struct Jewel_Queue* queue, struct Jewel* p_jewel) {
    p_jewel->next = NULL;
    if (queue->first == NULL) {
        queue->first = p_jewel;
    } else {
        queue->last->next = p_jewel;
    }
    queue->last = p_jewel;
}

int remove_first_from_queue(struct Jewel_Queue* queue) {
    if (queue->first == NULL) {
        return 0;
    } else {
        struct Jewel* current_first = queue->first;
        queue->first = queue->first->next;
        free(current_first);
        return 1;
    }
}

void print_queue(struct Jewel_Queue* queue) {
    struct Jewel* p_jewel = queue->first;
    if (p_jewel == NULL) {
        printf("Jewel_Queue is empty\n");
    } else {
        while (p_jewel != NULL) {
            print_jewel(p_jewel);
            p_jewel = p_jewel->next;
        }
    }
}