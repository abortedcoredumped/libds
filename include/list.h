#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct node Node;
typedef struct list List;

struct node {
    void *value;
    Node *prev;
    Node *next;
};

struct list {
    Node *head;
    Node *tail;

    size_t length;
};

// Exceptions
enum {
    LIST_NULL_POINTER = -32,
    LIST_FAIL_ALLOC_MEM
};

// This function returns a linked-list node
Node *make_node(void *value, Node *prev, Node *next);

// Initialize a empty list
List *make_list(void);

// Free a list from its head to its tail
int free_list(List *target);

// Push a value to a list at the end of the list
int list_push(List *target, void *value);

// Push a value the the from the front
int list_unshift(List *target, void *value);

#endif