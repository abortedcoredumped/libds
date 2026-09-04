#include <common/swap.h>

void swap(char *a, char *b, size_t size)
{
    char *tmp = malloc(size);

    if (tmp == NULL) {
        return; 
    }

    memmove(tmp, a, size);
    memmove(a, b, size);
    memmove(b, tmp, size);

    free(tmp);
}