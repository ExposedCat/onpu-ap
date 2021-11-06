#include "filter.h"

#include <stdio.h>

#include "entities.h"

void scanAndFilter(int records_number, char* filename) {
    char value;
    printf("Input value:\nV - Voltage\nA - Electric current\nL - Length\nT - Temperature\nH - Humidity\n> ");
    scanf("%c", &value);
    int guarantee;
    printf("Input guarantee in years:\n> ");
    scanf("%d", &guarantee);

    struct Instrument instruments[records_number];
    FILE* database = fopen(filename, "rb");
    fread(&instruments, sizeof(struct Instrument), records_number, database);
    int output = 0;
    for (int i = 0; i < records_number; ++i) {
        struct Instrument instrument = instruments[i];
        if (instrument.guarantee >= guarantee) {
            int value_found = 0;
            for (int i = 0; i < 100; ++i) {
                if (instrument.values[i].name == value) {
                    value_found = 1;
                    break;
                }
            }
            if (value_found) {
                printf("%s\n", instrument.name);
                output = 1;
            }
        }
    }
    if (!output) {
        printf("No records found.");
    }
}