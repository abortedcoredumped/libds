#include <stack.h>

Stack *make_stack(size_t capacity)
{
    return make_array(capacity);
}

int free_stack(Stack *target)
{
    return free_array(target);
}

int stack_push(Stack *target, void *value)
{
    return array_push(target, value);
}

void *stack_pop(Stack *target)
{
    if (target == NULL) {
        return NULL;
    }

    if (target->address == NULL) {
        return NULL;
    }

    if (target->length == 0) {
        return NULL;
    }

    return target->address[--target->length];
}

void *stack_top(Stack *target)
{
    if (target == NULL) {
        return NULL;
    }

    if (target->address == NULL) {
        return NULL;
    }

    if (target->length == 0) {
        return NULL;
    }

    return target->address[target->length - 1];
}