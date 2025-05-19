#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

void safe_concat(char *dest, const char *src, size_t size);
size_t custom_strlen(const char *str);

#endif
