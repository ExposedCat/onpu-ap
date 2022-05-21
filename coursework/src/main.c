#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entity-queue.h"
#include "util-process-input.h"
#include "util-ui.h"

int main() {
    printf("Coursework «Jewelry Store»");

    // Create empty queue
    struct Jewel_Queue jewels_queue;
    struct Jewel_Queue* jewels = &jewels_queue;
    init_queue(jewels);

    int exit = 0;
    do {
        exit = process_input(jewels, open_menu());
    } while (!exit);

    printf("\n________\nProgram finished successfully\n________\n");

    return 0;
}