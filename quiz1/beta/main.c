#include <stdint.h>
#include <stdio.h>
static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) { /* power of two? */
        return (sz + mask) & ~mask;
    }
    printf("~mask = %ld\n", ~mask);
    return (((sz + mask) / alignment) * alignment);
}

int main()
{
    printf("120, 4 : %ld\n", align_up(5, 4));
    printf("124, 4 : %ld\n", align_up(124, 4));

    return 0;
}
