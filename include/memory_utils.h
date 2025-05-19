#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include <stddef.h>

void *malloc_safe(size_t size);
void free_debug(void *ptr, const char *label);
void *calloc_safe(size_t count, size_t size);
void hex_dump(const void *mem, size_t len);
void simulate_leak(void);

#endif
