#include <queue.h>

#include <stdio.h>

int main(void)
{
    Queue *queue = make_queue();
    int arr[] = {2, 4, 6, 8};
    
    queue_enqueue(queue, &arr[0]);
    queue_enqueue(queue, &arr[1]);
    queue_enqueue(queue, &arr[2]);
    queue_enqueue(queue, &arr[3]);

    printf("%d\n", *(int *)queue_dequeue(queue));
    printf("%d\n", *(int *)queue_dequeue(queue));
    printf("%d\n", *(int *)queue_dequeue(queue));
    // printf("%d\n", *(int *)queue_dequeue(queue));
    // if (queue_front(queue))
    // printf("%d\n", *(int *)queue_dequeue(queue));

    printf("%d\n", *(int *)queue_front(queue));

    free_queue(queue);
    return 0;
}