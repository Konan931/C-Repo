#include "../include/memory_utils.h"
#include <stdio.h>
#include <stdlib.h>

void *malloc_safe(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "malloc_safe: Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void free_safe(void *ptr) {
    if (ptr) free(ptr);
}

void free_debug(void *ptr, const char *label) {
    if (ptr) {
        printf("Freeing memory for %s\n", label);
        free(ptr);
    }
}

void hex_dump(const void *mem, size_t len) {
    const unsigned char *p = mem;
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", p[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}