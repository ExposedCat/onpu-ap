#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entity-queue.h"

void assign(struct Jewel data, struct Jewel* jewel) {
    strcpy(jewel->name, data.name);
    strcpy(jewel->type, data.type);
    jewel->weight = data.weight;
    strcpy(jewel->stone_name, data.stone_name);
    jewel->carat_weight = data.carat_weight;
    jewel->price = data.price;
    strcpy(jewel->date, data.date);
}

void sort_by_price(struct Jewel_Queue* queue) {
    struct Jewel* p_jewel = queue->first;
    if (p_jewel != NULL) {
        int exit;
        do {
            exit = 1;
            p_jewel = queue->first;
            while (p_jewel != NULL && p_jewel->next != NULL) {
                if (p_jewel->price > p_jewel->next->price) {
                    exit = 0;
                    struct Jewel temp = *p_jewel;
                    assign(*(p_jewel->next), p_jewel);
                    assign(temp, p_jewel->next);
                }
                p_jewel = p_jewel->next;
            }
        } while (!exit);
    }
}