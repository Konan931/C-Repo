#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"
#include "hash_utils.h"

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

    return 0;
}
