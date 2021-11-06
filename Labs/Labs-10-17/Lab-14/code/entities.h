#ifndef __ENTITIES_H__
#define __ENTITIES_H__

struct Value {
    char name[101];
    int upper_bound;
    int bottom_bound;
    int error;
};

struct Customer {
    char full_name[101];
    char address[101];
    int instruments_number;
};

struct Instrument {
    char name[101];
    int guarantee;
    struct Value values[100];
    struct Customer customers[100];
};

#endif