#include <list.h>

struct node *make_node(void *value, struct node *prev, struct node *next)
{
    struct node *result = malloc(sizeof(struct node));

    if (result == NULL) {
        return NULL;
    }

    result->value = value;
    result->prev = prev;
    result->next = next;

    return result;
}

struct list *make_list(void)
{
    struct list *result = malloc(sizeof(struct list));

    if (result == NULL) {
        return NULL;
    }

    result->head = NULL;
    result->tail = NULL;
    result->length = 0;

    return result;
}

int list_push(struct list *target, void *value)
{
    if (target == NULL) {
        return LIST_NULL_POINTER;
    }

    struct node *n = make_node(value, target->tail, NULL);

    if (n == NULL) {
        return LIST_FAIL_ALLOC_MEM;
    }

    if (target->length == 0) {
        target->head = n;
        target->tail = n;
    } else {
        target->tail->next = n;
        target->tail = n;
    }

    target->length++;
    return target->length;
}

int free_list(struct list *target)
{
    if (target == NULL) {
        return LIST_NULL_POINTER;
    }

    struct node *cur = target->head, *next;

    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }

    target->head = NULL;
    target->tail = NULL;

    free(target);

    return 0;
}

int list_unshift(struct list *target, void *value)
{
    if (target == NULL) {
        return LIST_NULL_POINTER;
    }

    if (target->length == 0) {
        return list_push(target, value);
    } 

    struct node *n = make_node(value, NULL, target->head);

    if (n == NULL) {
        return LIST_FAIL_ALLOC_MEM;
    }
    
    target->head->prev = n;
    target->head = n;
    target->length++;

    return target->length;
}