#include <array.h>

#include <stdio.h>

int main(void)
{
    struct array *a = make_array(1);
    int arr[] = {2, 4, 6, 8, 10};

    array_push(a, &arr[0]);
    array_push(a, &arr[1]);
    array_push(a, &arr[2]);
    array_push(a, &arr[3]);

    array_set(a, 1, &arr[4]);
    array_set(a, 9, &arr[0]);

    for (int i = 0; i < a->length; i++) {
        printf("%d\n", *(int *)array_get(a, i));
    }


    printf("len=%zu, cap=%zu\n", a->length, a->capacity);

    free_array(a);
    return 0;
}