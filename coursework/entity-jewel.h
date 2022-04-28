#ifndef ENTITY_JEWEL
#define ENTITY_JEWEL

struct Jewel {
    char name[50];
    char type[50];
    double weight;
    int number;
    char stone_name[50];
    double carat_weight;
    double price;
    char date[11];
    struct Jewel* next;
};

extern struct Jewel* create_jewel();
extern void input_jewel(struct Jewel* jewel);
extern void print_jewel(struct Jewel* jewel);

#endif