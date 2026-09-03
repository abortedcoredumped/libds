#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdlib.h>

struct array {
    void **address;
    size_t length;
    size_t capacity;
};

enum {
    ARRAY_NULL_POINTER,
    ARRAY_NULL_BASE_ADR
};

// Make and return an array, you should provide
// the capacity of it
struct array *make_array(size_t capacity);

// Free the allocated memory of where an array
// over taken
int free_array(struct array *target);

// Set a value to a given index of an array
int array_set(struct array *target, size_t index, void *value);

// Push a value at the tail of an array
int array_push(struct array *target, void *value);

#endif