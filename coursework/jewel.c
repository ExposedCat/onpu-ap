#include "jewel.h"

#include <stdio.h>

struct Jewel* create_jewel() {
    struct Jewel* p_jewel = malloc(sizeof(struct Jewel));
    return p_jewel;
}

void input_jewel(struct Jewel* p_jewel) {
    printf("Input jewel data by template (in one line, separated by spaces):\n");
    printf("name type weight number_of_stones stone_name carat_weight price date:\n");
    scanf("%s", p_jewel->name);
    scanf("%s", p_jewel->type);
    scanf("%lf", &p_jewel->weight);
    scanf("%d", &p_jewel->number);
    scanf("%s", p_jewel->stone_name);
    scanf("%d", &p_jewel->carat_weight);
    scanf("%lf", &p_jewel->price);
    scanf("%s", p_jewel->date);
}

void print_jewel(struct Jewel* p_jewel) {
    const char* template =
        "Name: %s\n\
Type: %s\n\
Weight: %.2lf\n\
Number of stones: %d\n\
Stone name: %s\n\
Carat weight: %d\n\
Price: %.3lf\n\
Date: %s\n";

    printf(
        template,
        p_jewel->name,
        p_jewel->type,
        p_jewel->weight,
        p_jewel->number,
        p_jewel->stone_name,
        p_jewel->carat_weight,
        p_jewel->price,
        p_jewel->date);
}