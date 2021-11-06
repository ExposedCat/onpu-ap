#include <stdio.h>

#include "filter.h"
#include "initialize.h"

void main() {
    int records_number;
    printf("Input records number: ");
    scanf("%d", &records_number);
    int write_success = scanAndWrite(records_number, "gi-database");
    if (!write_success) {
        printf("An error occurred while creating database\n");
        return;
    }
    int filter_success = scanAndFilter(records_number, "gi-database");
    if (!filter_success) {
        printf("An error occurred while opening database");
    }
    printf("\n");
}