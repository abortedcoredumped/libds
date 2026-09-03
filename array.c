#include <array.h>

struct array *make_array(size_t capacity) 
{
    struct array *result = malloc(sizeof(struct array));

    if (result == NULL) {
        return NULL;
    }

    result->address = malloc(capacity * sizeof(void *));

    if (result->address == NULL) {
        free(result);
        return NULL;
    }

    result->capacity = capacity;
    result->length = 0;
}

int free_array(struct array *target)
{
    if (target == NULL) {
        return ARRAY_NULL_POINTER;
    }

    if (target->address == NULL) {
        free(target);
        return ARRAY_NULL_BASE_ADR;
    }

    free(target->address);
    free(target);

    target = NULL;
}