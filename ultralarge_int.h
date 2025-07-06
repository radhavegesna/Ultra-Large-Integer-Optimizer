#ifndef ULTRALARGE_INT_H
#define ULTRALARGE_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 1000  // Maximum number of digits in integer

typedef struct {
    int digits[MAX_DIGITS];  // Array to store digits
    int size;                // Number of digits in the integer
} ultralargeint;

// Function prototypes
void init_large_int(ultralargeint *li);
void set_large_int(ultralargeint *li, const char *value);
void add_large_ints(const ultralargeint *a, const ultralargeint *b, ultralargeint *result);
int compare_large_ints(const void *a, const void *b);
void subtract_large_ints(const ultralargeint *a, const ultralargeint *b, ultralargeint *result);
int count_pairs(ultralargeint *data, int n, const ultralargeint *target);

#endif // LARGE_INT_H