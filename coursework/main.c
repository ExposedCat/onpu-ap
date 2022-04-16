#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

int main() {
    printf("Coursework «Jewelry Store»\n________\n");

    // Create empty queue 
    struct Jewel_Queue jewels;
    init_queue(&jewels);

    // Create items and fill queue
    for (int i = 0; i < 2; ++i) {
        struct Jewel* p_jewel = create_jewel();
        input_jewel(p_jewel);
        add_to_queue(&jewels, p_jewel);
    }

    // Remove first element (test deletion)
    remove_first_from_queue(&jewels);

    // Print queue
    print_queue(&jewels);

    return 0;
}