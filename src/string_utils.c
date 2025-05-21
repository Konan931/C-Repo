#include "../include/string_utils.h"
// This file contains utility functions for string manipulation and conversion.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

size_t string_length(const char *str) { return strlen(str); }
int string_to_int(const char *str) { return atoi(str); }
float string_to_float(const char *str) { return strtof(str, NULL); }
double string_to_double(const char *str) { return strtod(str, NULL); }
void int_to_string(int value, char *buffer, size_t size) {
    snprintf(buffer, size, "%d", value);
}
void float_to_string(float value, char *buffer, size_t size) {
    snprintf(buffer, size, "%f", value);
}
void double_to_string(double value, char *buffer, size_t size) {
    snprintf(buffer, size, "%lf", value);
}