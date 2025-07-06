#include "ultralarge_int.h"

// Initialize a ultralargeint
void init_large_int(ultralargeint *li) {
    li->size = 0;
    memset(li->digits, 0, sizeof(li->digits));
}

// Set a ultralargeint from a string
void set_large_int(ultralargeint *li, const char *value) {
    init_large_int(li);
    li->size = strlen(value);
    for (int i = 0; i < li->size; i++) {
        li->digits[li->size - 1 - i] = value[li->size - 1 - i] - '0';
    }
}

// Compare two ultralargeints
int compare_large_ints(const void *a, const void *b) {
    const ultralargeint *pa = (const ultralargeint *)a;
    const ultralargeint *pb = (const ultralargeint *)b;
    if (pa->size != pb->size) return pa->size < pb->size ? -1 : 1;
    for (int i = pa->size - 1; i >= 0; i--) {
        if (pa->digits[i] != pb->digits[i]) return pa->digits[i] < pb->digits[i] ? -1 : 1;
    }
    return 0;
}

// Subtract two ultralargeints
void subtract_large_ints(const ultralargeint *a, const ultralargeint *b, ultralargeint *result) {
    init_large_int(result);
    int borrow = 0;
    for (int i = 0; i < a->size; i++) {
        int sub = a->digits[i] - (i < b->size ? b->digits[i] : 0) - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result->digits[i] = sub;
    }
    result->size = a->size;
    while (result->size > 0 && result->digits[result->size - 1] == 0) {
        result->size--;
    }
}

