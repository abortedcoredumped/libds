#include <array.h>
#include <common/reverse.h>

#include <stdio.h>

int main(void)
{
    Array *arr = make_array(2);
    int iarr[] = {2, 4, 6, 8};
    
    array_push(arr, &iarr[0]);
    array_push(arr, &iarr[1]);
    array_push(arr, &iarr[2]);
    array_push(arr, &iarr[3]);

    reverse(arr->address, sizeof(void *), 4);

    for (int i = 0; i < 4; i++) {
        printf("%d\n", *(int *)arr->address[i]);
    }

    free_array(arr);
    return 0;
}