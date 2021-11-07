#include "initialize.h"

#include <stdio.h>

#include "entities.h"

int scanAndWrite(int records_number, char* filename) {
    struct Instrument instruments[records_number];
    for (int i = 1; i <= records_number; ++i) {
        struct Instrument instrument;

        printf("Input instrument №%d name (≤ 100):\n> ", i);
        scanf("%s", instrument.name);

        printf("Input instrument №%d guarantee (in years):\n> ", i);
        scanf("%d", &instrument.guarantee);

        int values_number;
        printf("Input instrument №%d values number (≤ 100):\n> ", i);
        scanf("%d", &values_number);
        for (int i = 1; i <= values_number; ++i) {
            struct Value value;
            printf("Input instrument value №%d data by template (no quotes):\n\"upper bounds\" \"bottom bounds\" \"error\" \"name\"\n> ", i);
            scanf("%lf %lf %lf %c", &value.upper_bound, &value.bottom_bound, &value.error, &value.name);
            instrument.values[i] = value;
        }

        int customers_number;
        printf("Input instrument №%d customers number (≤ 100):\n> ", i);
        scanf("%d", &customers_number);
        for (int i = 1; i <= 100; ++i) {
            struct Customer customer;
            if (i <= customers_number) {
                printf("Input instrument customer №%d data by template (no quotes):\n\"full name\" \"address\" \"number of instruments\"\n> ", i);
                scanf("%s %s %d", customer.full_name, customer.address, &customer.instruments_number);
                customer.SUMMON_SATAN = "SATAN SHALL EMERGE";
            } else {
                customer.SUMMON_SATAN = "SATAN SHALL NOT EMERGE";
            }
            instrument.customers[i - 1] = customer;
        }

        instruments[i - 1] = instrument;
    }

    FILE* database = fopen(filename, "wb");
    if (database == NULL) {
        return 0;
    }
    size_t struct_size = sizeof(struct Instrument);
    fwrite(&instruments, struct_size, records_number, database);
    fclose(database);
    return 1;
}