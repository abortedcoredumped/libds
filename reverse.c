#include <common/reverse.h>

void reverse(void *target, size_t size, size_t len)
{
    if (len <= 1 || target == NULL) {
        return;
    }

    char *left = (char *)target;
    char *right = (char *)target + size * (len - 1);

    while (left < right) {
        swap(left, right, size);
        left += size;
        right -= size;
    }
}