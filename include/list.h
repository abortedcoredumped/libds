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

struct node *make_node(void *value, struct node *prev, struct node *next);

struct list *make_list(void);

int free_list(struct list *target);

int list_push(struct list *target, void *value);

int list_unshift(struct list *target, void *value);

#endif