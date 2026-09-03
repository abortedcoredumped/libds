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

int array_set(struct array *target, size_t index, void *value)
{
    if (target == NULL) {
        return ARRAY_NULL_POINTER;  
    }

    if (target->address == NULL) {
        return ARRAY_NULL_BASE_ADR;
    }

    if (index < 0 || index > target->length) {
        return ARRAY_ILLEGAL_INDEX;
    }

    if (target->length == target->capacity) {
        void **tmp = 
            realloc(
                target->address,
                (ARRAY_CAP_PLUS+target->capacity) * sizeof(void*)
            );
        
        if (tmp == NULL) {
            return ARRAY_FAIL_ALLOC_MEM;
        }

        target->address = tmp;
        target->capacity += ARRAY_CAP_PLUS;
    }

    target->address[index] = value;
    
    if (index == target->length) {
        target->length++;
    } 

    return 0;
}

void *array_get(struct array *target, size_t index)
{
    if (target == NULL || target->address == NULL ||
        index < 0 || index >= target->capacity) {
        return NULL;
    }

    return target->address[index];
}

int array_push(struct array *target, void *value)
{
    return array_set(target, target->length, value);
}