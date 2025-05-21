// Source file for file utility functions(file_utils.c)
#include "../include/file_utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int file_exists(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f) { fclose(f); return 1; }
    return 0;
}
size_t file_size(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return 0;
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fclose(f);
    return size;
}
