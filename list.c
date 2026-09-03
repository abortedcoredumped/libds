#include <list.h>

Node *make_node(void *value, Node *prev, Node *next)
{
    Node *result = malloc(sizeof(Node));

    if (result == NULL) {
        return NULL;
    }

    result->value = value;
    result->prev = prev;
    result->next = next;

    return result;
}

List *make_list(void)
{
    List *result = malloc(sizeof(List));

    if (result == NULL) {
        return NULL;
    }

    result->head = NULL;
    result->tail = NULL;
    result->length = 0;

    return result;
}

int list_push(List *target, void *value)
{
    if (target == NULL) {
        return LIST_NULL_POINTER;
    }

    Node *n = make_node(value, target->tail, NULL);

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

int free_list(List *target)
{
    if (target == NULL) {
        return LIST_NULL_POINTER;
    }

    Node *cur = target->head, *next;

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

int list_unshift(List *target, void *value)
{
    if (target == NULL) {
        return LIST_NULL_POINTER;
    }

    if (target->length == 0) {
        return list_push(target, value);
    } 

    Node *n = make_node(value, NULL, target->head);

    if (n == NULL) {
        return LIST_FAIL_ALLOC_MEM;
    }
    
    target->head->prev = n;
    target->head = n;
    target->length++;

    return target->length;
}