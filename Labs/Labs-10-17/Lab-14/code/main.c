#include <stdio.h>

#include "filter.h"
#include "initialize.h"

void main() {
    int records_number;
    printf("Input recordsg number: ");
    scanf("%d", &records_number);
    scanAndWrite(records_number, "gi-database");
    scanAndFilter(records_number, "gi-database");
    printf("\n");
}