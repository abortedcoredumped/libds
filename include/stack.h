#ifndef STACK_H
#define STACK_H

#include <array.h>

typedef Array Stack;

// Make a stack
Stack *make_stack(size_t capacity);

// Free a stack
int free_stack(Stack *target);

// Push a data at the tail
int stack_push(Stack *target, void *value);

// Pop out the top
void *stack_pop(Stack *target);

// Get the top
void *stack_top(Stack *target);

#endif