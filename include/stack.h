#ifndef STACK_H
#define STACK_H

#include <array.h>

typedef Array Stack;

Stack *make_stack(size_t capacity);

int free_stack(Stack *target);

int stack_push(Stack *target, void *value);

void *stack_pop(Stack *target);

void *stack_top(Stack *target);

#endif