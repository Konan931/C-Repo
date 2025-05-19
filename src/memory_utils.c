#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/memory_utils.h"

void *malloc_safe(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "[ERROR] malloc failed (%zu bytes)\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *calloc_safe(size_t count, size_t size) {
    void *ptr = calloc(count, size);
    if (!ptr) {
        fprintf(stderr, "[ERROR] calloc failed (%zu x %zu bytes)\n", count, size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void free_debug(void *ptr, const char *label) {
    if (!ptr) {
        fprintf(stderr, "[WARN] Tried to free null pointer (%s)\n", label);
        return;
    }
    free(ptr);
    printf("[DEBUG] Freed pointer (%s)\n", label);
}

// Print memory contents in hex format
void hex_dump(const void *mem, size_t len) {
    const unsigned char *ptr = mem;
    printf("[HEXDUMP] %zu bytes:\n", len);
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", ptr[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

// Simulate a memory leak (for testing with Valgrind)
void simulate_leak(void) {
    void *leak = malloc(123);
    memset(leak, 0x41, 123); // fill with 'A'
    // No free() call here — intentional leak!
}
