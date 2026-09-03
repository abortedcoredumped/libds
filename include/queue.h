#ifndef QUEUE_H
#define QUEUE_H

#include <list.h>

typedef List Queue;

// Make a queue
Queue *make_queue(void);

// Free a queue
int free_queue(Queue *target);

// Put a value at the rear of a queue
int queue_enqueue(Queue *target, void *value);

// Dequeue the first data
void *queue_dequeue(Queue *target);

// Get the head data
void *queue_front(Queue *target);

#endif