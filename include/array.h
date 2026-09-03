#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct array Array;

struct array {
    void **address;
    size_t length;
    size_t capacity;
};

// Exceptions
enum {
    ARRAY_NULL_POINTER = 1,
    ARRAY_NULL_BASE_ADR,
    ARRAY_ILLEGAL_INDEX,
    ARRAY_FAIL_ALLOC_MEM
};

// Resize increments
enum {
    ARRAY_CAP_PLUS = 10
};

// Make and return an array, you should provide
// the capacity of it
Array *make_array(size_t capacity);

// Free the allocated memory of where an array
// over taken
int free_array(Array *target);

// Set a value to a given index of an array
// Returns 0 when success
int array_set(Array *target, size_t index, void *value);

// Push a value at the tail of an array
// Return value see array_set()
int array_push(Array *target, void *value);

// Get a value from a specific index
void *array_get(Array *target, size_t index);

#endif