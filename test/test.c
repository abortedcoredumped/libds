#include <stack.h>

#include <stdio.h>

int main(void)
{
    Stack *stack = make_stack(2);
    int arr[] = {2, 4, 6, 8};

    stack_push(stack, &arr[0]);
    stack_push(stack, &arr[1]);
    stack_push(stack, &arr[2]);
    stack_push(stack, &arr[3]);

    while (stack_top(stack)) {
        printf("%d\n", *(int *)stack_pop(stack));
    }

    free_stack(stack);
    return 0;
}