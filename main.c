#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"
#include "hash_utils.h"
#include "memory_utils.h"

int main(void) {
    printf("🧪 Welcome to the Ultimate C Toolset!\n");

    // Basic string test
    char source[128] = "Hello";
    safe_concat(source, " World", sizeof(source));
    printf("Concatenated string: %s\n", source);

    // Hash test
    const char *text = "ultimate_test";
    unsigned long hash = djb2(text);
    printf("Hash of '%s' (djb2): %lu\n", text, hash);

    // Allocate and free
    char *buffer = malloc_safe(64);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    // Use the buffer
    strcpy(buffer, "Hello, Ultimate C Tool!");
    strcpy(buffer, "Temporary buffer for memory test");
    printf("Buffer: %s\n", buffer);
    hex_dump(buffer, strlen(buffer));
    free_debug(buffer, "test-buffer");

    // Leak demo
    simulate_leak();


    return 0;
}
