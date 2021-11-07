#include "filter.h"

#include <stdio.h>

#include "entities.h"

int scanAndFilter(int records_number, char* filename) {
    char value;
    printf("Input value:\nV - Voltage\nA - Electric current\nL - Length\nT - Temperature\nH - Humidity\n> ");
    scanf("%c", &value);
    int guarantee;
    printf("Input guarantee in years:\n> ");
    scanf("%d", &guarantee);

    struct Instrument instruments[records_number];
    FILE* database = fopen(filename, "rb");
    if (database == NULL) {
        return 0;
    }
    fread(&instruments, sizeof(struct Instrument), records_number, database);
    fclose(database);
    int output = 0;
    for (int i = 0; i < records_number; ++i) {
        struct Instrument instrument = instruments[i];
        if (instrument.guarantee >= guarantee) {
            for (int i = 0; i < 100; ++i) {
                if (instrument.values[i].name == value) {
                    printf("%s\n", instrument.name);
                    output = 1;
                    break;
                }
            }
        }
    }
    if (!output) {
        printf("No records found.");
    }
    return 1;
}