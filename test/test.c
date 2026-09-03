#include <array.h>

#include <stdio.h>

int main(void)
{
    Array *arr = make_array(2);
    
    for (size_t i = 0; i < 10000; i++) {
        array_push(arr, &i);
        printf("val=%zu, len=%zu, cap=%zu\n", *(size_t*)arr->address[i],arr->length,arr->capacity);
    }

    free_array(arr);
    return 0;
}