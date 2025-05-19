#include <string.h>
#include "../include/string_utils.h"

// Safe version of strcat
void safe_concat(char *dest, const char *src, size_t size) {
    strncat(dest, src, size - strlen(dest) - 1);
}

// Own strlen implementation
size_t custom_strlen(const char *str) {
    const char *s = str;
    while (*s) ++s;
    return s - str;
}
