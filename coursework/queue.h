#include "jewel.h"

struct Jewel_Queue {
    struct Jewel* first;
    struct Jewel* last;
};

extern void init_queue(struct Jewel_Queue* queue);
extern void add_to_queue(struct Jewel_Queue* queue, struct Jewel* p_jewel);
extern int remove_first_from_queue(struct Jewel_Queue* queue);
extern void print_queue(struct Jewel_Queue* queue);