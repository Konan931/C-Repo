#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

size_t string_length(const char *str);
int string_to_int(const char *str);
float string_to_float(const char *str);
double string_to_double(const char *str);
void int_to_string(int value, char *buffer, size_t size);
void float_to_string(float value, char *buffer, size_t size);
void double_to_string(double value, char *buffer, size_t size);

#endif