#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>

// Read a file and return its content as a string
char* read_file(const char *filename);

// Write a string to a file
void write_file(const char *filename, const char *content);

#endif
