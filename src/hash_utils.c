#include "../include/hash_utils.h"

// djb2 hash function
unsigned long djb2(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}

// FNV-1a hash function
unsigned long fnv1a(const char *str) {
    unsigned long hash = 14695981039346656037UL;
    while (*str) {
        hash ^= (unsigned char)*str++;
        hash *= 1099511628211UL;
    }
    return hash;
}
