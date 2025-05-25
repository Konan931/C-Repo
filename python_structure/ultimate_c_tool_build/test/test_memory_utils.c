// Test file for test_memory_utils.c
#include <stdio.h>
#include <string.h>
#include "../include/memory_utils.h"

int main(void) {
    printf("== Memory Utils Tests ==\n");
    char *mem = malloc_safe(32);
    strcpy(mem, "Hello Memory!");
    printf("Allocated: %s\n", mem);
    hex_dump(mem, strlen(mem));
    free_debug(mem, "mem");
    printf("All memory_utils tests done!\n");
    return 0;
}
