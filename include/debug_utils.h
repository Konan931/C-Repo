#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <stdio.h>

#define ASSERT(condition) if (!(condition)) { fprintf(stderr, "[ERROR] Assertion failed: %s\n", #condition); exit(EXIT_FAILURE); }
#define LOG(message) printf("[LOG] %s\n", message)

void trace(const char *message);

#endif
