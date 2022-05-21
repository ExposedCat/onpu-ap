#include "entity-queue.h"

void add_jewel(struct Jewel_Queue* jewels) {
    struct Jewel* p_jewel = create_jewel();
    input_jewel(p_jewel);
    add_to_queue(jewels, p_jewel);
}