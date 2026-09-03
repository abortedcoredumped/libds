#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct node {
    void *value;
    struct node *prev;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;

    size_t length;
};

// Exceptions
enum {
    LIST_NULL_POINTER = -32,
    LIST_FAIL_ALLOC_MEM
};

// This function returns a linked-list node
struct node *make_node(void *value, struct node *prev, struct node *next);

// Initialize a empty list
struct list *make_list(void);

// Free a list from its head to its tail
int free_list(struct list *target);

// Push a value to a list at the end of the list
int list_push(struct list *target, void *value);

// Push a value the the from the front
int list_unshift(struct list *target, void *value);

#endif