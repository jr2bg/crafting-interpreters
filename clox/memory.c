#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);
    // case when there is a fail in realloc, maybe due to lack of memory
    if (result == NULL) exit(1);
    return result;
}