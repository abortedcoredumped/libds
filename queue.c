#include <queue.h>

Queue *make_queue(void)
{
    return make_list();
}

int free_queue(Queue *target)
{
    return free_list(target);
}

int queue_enqueue(Queue *target, void *value)
{
    return list_push(target, value);
}

void *queue_dequeue(Queue *target)
{
    if (target == NULL) {
        return NULL;
    }

    if (target->length == 0) {
        return NULL;
    }

    void *res = target->head->value;
    Node *node = target->head;

    if (target->head->next == NULL) {
        target->head = NULL;
        target->tail = NULL;
    } else {
        target->head->next->prev = NULL;
        target->head = target->head->next;
    }

    target->length--;

    free(node);
    return res;
}

void *queue_front(Queue *target)
{
    if (target == NULL) {
        return NULL;
    }

    if (target->length == 0) {
        return NULL;
    }

    return target->head->value;
}