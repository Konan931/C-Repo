#include "../include/string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// String Measurement
size_t string_length(const char *str) {
    return str ? strlen(str) : 0;
}

// String Copying
char *string_copy(const char *str) {
    if (!str) return NULL;
    size_t len = strlen(str);
    char *copy = malloc(len + 1);
    if (copy) strcpy(copy, str);
    return copy;
}

// String Concatenation
char *string_concat(const char *a, const char *b) {
    if (!a && !b) return NULL;
    if (!a) return string_copy(b);
    if (!b) return string_copy(a);
    size_t len_a = strlen(a), len_b = strlen(b);
    char *res = malloc(len_a + len_b + 1);
    if (res) {
        strcpy(res, a);
        strcat(res, b);
    }
    return res;
}

// String Comparison
int string_compare(const char *a, const char *b) {
    if (!a && !b) return 0;
    if (!a) return -1;
    if (!b) return 1;
    return strcmp(a, b);
}
// String to Integer Conversion
int string_to_int(const char *str) {
    if (!str) return 0;
    return (int)strtol(str, NULL, 10);
}
// String to Float Conversion
float string_to_float(const char *str) {
    if (!str) return 0.0f;
    return (float)strtof(str, NULL);
}
// String to Double Conversion
double string_to_double(const char *str) {
    if (!str) return 0.0;
    return strtod(str, NULL);
}
// Integer to String Conversion
void int_to_string(int value, char *buffer, size_t bufsize) {
    if (buffer) {
        snprintf(buffer, bufsize, "%d", value);
    }
}
// Float to String Conversion
void float_to_string(float value, char *buffer, size_t bufsize) {
    if (buffer) {
        snprintf(buffer, bufsize, "%.6f", value);
    }
}
// Double to String Conversion
void double_to_string(double value, char *buffer, size_t bufsize) {
    if (buffer) {
        snprintf(buffer, bufsize, "%.15g", value);
    }
}

// String to Uppercase
char *string_to_upper(const char *str) {
    if (!str) return NULL;
    char *upper = string_copy(str);
    if (upper) {
        for (char *p = upper; *p; ++p) *p = toupper((unsigned char)*p);
    }
    return upper;
}
// String to Lowercase
char *string_to_lower(const char *str) {
    if (!str) return NULL;
    char *lower = string_copy(str);
    if (lower) {
        for (char *p = lower; *p; ++p) *p = tolower((unsigned char)*p);
    }
    return lower;
}
// String Trim (removes leading and trailing whitespace)
char *string_trim(const char *str) {
    if (!str) return NULL;
    const char *start = str;
    while (isspace((unsigned char)*start)) start++;
    const char *end = str + strlen(str) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    size_t len = end - start + 1;
    char *trimmed = malloc(len + 1);
    if (trimmed) {
        strncpy(trimmed, start, len);
        trimmed[len] = '\0';
    }
    return trimmed;
}
// String Find (returns a pointer to the first occurrence of needle in haystack)
char *string_find(const char *haystack, const char *needle) {
    if (!haystack || !needle) return NULL;
    return strstr(haystack, needle);
}
// String Contains (checks if needle is in haystack)
int string_contains(const char *haystack, const char *needle) {
    if (!haystack || !needle) return 0;
    return strstr(haystack, needle) != NULL;
}
// String Is Uppercase
int string_is_upper(const char *str) {
    if (!str) return 0;
    for (const char *p = str; *p; ++p) {
        if (!isupper((unsigned char)*p)) return 0;
    }
    return 1;
}
// String Is Lowercase
int string_is_lower(const char *str) {
    if (!str) return 0;
    for (const char *p = str; *p; ++p) {
        if (!islower((unsigned char)*p)) return 0;
    }
    return 1;
}
// String Is Numeric
int string_is_numeric(const char *str) {
    if (!str || *str == '\0') return 0;
    for (const char *p = str; *p; ++p) {
        if (!isdigit((unsigned char)*p)) return 0;
    }
    return 1;
}
// String Is Alphanumeric
int string_is_alphanumeric(const char *str) {
    if (!str || *str == '\0') return 0;
    for (const char *p = str; *p; ++p) {
        if (!isalnum((unsigned char)*p)) return 0;
    }
    return 1;
}
// String Is Alpha
int string_is_alpha(const char *str) {
    if (!str || *str == '\0') return 0;
    for (const char *p = str; *p; ++p) {
        if (!isalpha((unsigned char)*p)) return 0;
    }
    return 1;
}

void string_is_alpha_safe(const char *str, int *result) {
    if (result) *result = string_is_alpha(str);
}
// String Is Alphanumeric Safe
void string_is_alphanumeric_safe(const char *str, int *result) {
    if (result) *result = string_is_alphanumeric(str);
}

// String Is Empty
int string_is_empty(const char *str) {
    return str == NULL || *str == '\0';
}
// String Is Not Empty
int string_is_not_empty(const char *str) {
    return str != NULL && *str != '\0';
}

// String Is Null
int string_is_null(const char *str) {
    return str == NULL;
}
// String Is Not Null
int string_is_not_null(const char *str) {
    return str != NULL;
}
// String Is Empty or Whitespace
int string_is_empty_or_whitespace(const char *str) {
    if (!str || *str == '\0') return 1; // Empty string is considered empty
    for (const char *p = str; *p; ++p) {
        if (!isspace((unsigned char)*p)) return 0; // Found a non-whitespace character
    }
    return 1; // All characters are whitespace
}
// String Split (splits a string by a delimiter and returns an array of strings)
char **string_split(const char *str, const char *delimiter, size_t *count) {
    if (!str || !delimiter || !count) return NULL;
    char *temp = string_copy(str);
    if (!temp) return NULL;

    size_t capacity = 10;
    char **result = malloc(capacity * sizeof(char *));
    if (!result) {
        free(temp);
        return NULL;
    }

    size_t index = 0;
    char *token = strtok(temp, delimiter);
    while (token) {
        if (index >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(char *));
            if (!result) {
                free(temp);
                return NULL;
            }
        }
        result[index++] = string_copy(token);
        token = strtok(NULL, delimiter);
    }

    free(temp);
    *count = index;
    return result;
}
// Free String Array
void string_free_array(char **array, size_t count) {
    if (!array) return;
    for (size_t i = 0; i < count; ++i) {
        free(array[i]);
    }
    free(array);
}
// String Replace (replaces all occurrences of old with new in str)
char *string_replace(const char *str, const char *old, const char *new) {
    if (!str || !old || !new) return NULL;
    size_t old_len = strlen(old);
    size_t new_len = strlen(new);
    if (old_len == 0) return string_copy(str); // Avoid infinite loop if old is empty
    if (strcmp(old, new) == 0) return string_copy(str); // If old and new are the same, return a copy of str

    // Count occurrences of old in str
    size_t count = 0;
    const char *pos = str;
    while ((pos = strstr(pos, old)) != NULL) {
        count++;
        pos += old_len;
    }

    // If no occurrences, return a copy of the original string
    if (count == 0) return string_copy(str);

    // Allocate memory for the new string
    size_t new_size = strlen(str) + count * (new_len - old_len) + 1;
    char *result = malloc(new_size);
    if (!result) return NULL;

    // Replace occurrences
    char *current = result;
    const char *src = str;
    while ((pos = strstr(src, old)) != NULL) {
        size_t len_before_old = pos - src;
        strncpy(current, src, len_before_old);
        current += len_before_old;
        strcpy(current, new);
        current += new_len;
        src = pos + old_len; // Move past the old substring
    }

    // Copy the remaining part of the original string
    strcpy(current, src);

    return result;
}
// String Join (joins an array of strings with a delimiter)
char *string_join(char **strings, size_t count, const char *delimiter) {
    if (!strings || count == 0 || !delimiter) return NULL;
    size_t delimiter_len = strlen(delimiter);
    size_t total_length = 0;
    for (size_t i = 0; i < count; ++i) {
        if (strings[i]) {
            total_length += strlen(strings[i]);
        }
    }
    if (count > 1) {
        total_length += (count - 1) * delimiter_len; // Add space for delimiters
    }
    char *result = malloc(total_length + 1);
    if (!result) return NULL;
    result[0] = '\0'; // Initialize as empty string
    for (size_t i = 0; i < count; ++i) {
        if (strings[i]) {
            if (i > 0) {
                strcat(result, delimiter); // Add delimiter before each string except the first
            }
            strcat(result, strings[i]);
        }
    }
    return result;
}