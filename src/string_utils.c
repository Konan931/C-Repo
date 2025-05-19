#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

// Safe version of strcpy
void safe_copy(char *dest, const char *src, size_t size) {
    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0'; // Ensure null termination
}
// Own strcmp implementation
int custom_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
// Safe version of strstr
const char *safe_find(const char *haystack, const char *needle) {
    return strstr(haystack, needle);
}
// Own strtok implementation
char *custom_strtok(char *str, const char *delim) {
    static char *last = NULL;
    if (str == NULL) str = last;
    str += strspn(str, delim);
    if (*str == '\0') return NULL;
    last = str + strcspn(str, delim);
    if (*last != '\0') {
        *last++ = '\0';
    }
    return str;
}
// Safe version of strtok
int string_split(const char *str, char delimiter, char **tokens, int max_tokens) {
    int count = 0;
    char *token = strtok(strdup(str), &delimiter);
    while (token != NULL && count < max_tokens) {
        tokens[count++] = token;
        token = strtok(NULL, &delimiter);
    }
    return count;
}
// Own strrev implementation
void string_reverse(char *str) {
    char *start = str;
    char *end = str + custom_strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}
// Safe version of atoi
int string_to_int(const char *str) {
    return (int)strtol(str, NULL, 10);
}
// Own itoa implementation
void int_to_string(int value, char *str, size_t size) {
    snprintf(str, size, "%d", value);
}
// Safe version of atof
float string_to_float(const char *str) {
    return (float)strtod(str, NULL);
}
// Own ftoa implementation
void float_to_string(float value, char *str, size_t size) {
    snprintf(str, size, "%.2f", value);
}
// Safe version of strtod
double string_to_double(const char *str) {
    return strtod(str, NULL);
}
// Own dtoa implementation
void double_to_string(double value, char *str, size_t size) {
    snprintf(str, size, "%.4f", value);
}
// Safe version of strtol
int string_to_long(const char *str) {
    return (int)strtol(str, NULL, 10);
}
// Own ltoa implementation
void long_to_string(long value, char *str, size_t size) {
    snprintf(str, size, "%ld", value);
}
// Safe version of strtoul
unsigned long string_to_unsigned_long(const char *str) {
    return strtoul(str, NULL, 10);
}
// Own ultoa implementation
void unsigned_long_to_string(unsigned long value, char *str, size_t size) {
    snprintf(str, size, "%lu", value);
}
// Safe version of strtoll
long long string_to_long_long(const char *str) {
    return strtoll(str, NULL, 10);
}
// Own lltoa implementation
void long_long_to_string(long long value, char *str, size_t size) {
    snprintf(str, size, "%lld", value);
}
// Safe version of strtoull
unsigned long long string_to_unsigned_long_long(const char *str) {
    return strtoull(str, NULL, 10);
}
// Own ulltoa implementation
void unsigned_long_long_to_string(unsigned long long value, char *str, size_t size) {
    snprintf(str, size, "%llu", value);
}
// Safe version of strtof
float string_to_float_safe(const char *str) {
    return (float)strtof(str, NULL);
}
// Own ftoa_safe implementation
void float_to_string_safe(float value, char *str, size_t size) {
    snprintf(str, size, "%.2f", value);
}

// Safe string copy with limit
char* safe_strcpy(char *dest, const char *src, size_t n) {
    if (n > 0) {
        strncpy(dest, src, n - 1);
        dest[n - 1] = '\0';
    }
    return dest;
}

// Safe string concatenation with limit
char* safe_strcat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t i;
    for (i = 0; i < n - dest_len - 1 && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}

// Reverse a string in place
void reverse_string(char *str) {
    size_t length = strlen(str);
    size_t i;
    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

