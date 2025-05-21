#include "../include/hash_utils.h"
#include <string.h>

void simple_hash(const char *input, char *output, size_t out_size) {
    size_t len = strlen(input);
    for (size_t i = 0; i < out_size-1; i++)
        output[i] = (char)((input[i % len] + i) % 256);
    output[out_size-1] = '\0';
}