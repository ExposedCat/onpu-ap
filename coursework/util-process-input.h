#include "entity-queue.h"

int process_input(struct Jewel_Queue* jewels, int input);
int process_field_input(struct Jewel* jewel, int input);
int field_equal_to(struct Jewel* jewel, int field, char* string, int number);
int input_field_data(int field, char* string, int* number);