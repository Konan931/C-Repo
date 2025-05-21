#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stddef.h>

int file_exists(const char *filename);
size_t file_size(const char *filename);

#endif