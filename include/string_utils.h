#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

// String Measurement
size_t string_length(const char *str);

// String Copying
char *string_copy(const char *str);

// String Concatenation
char *string_concat(const char *str1, const char *str2);

// String Substring
char *string_substring(const char *str, size_t start, size_t length);

// String Manipulation
char *string_to_lower(const char *str);
char *string_to_upper(const char *str);
char *string_trim(const char *str);
char *string_replace(const char *str, const char *old, const char *newstr);

// String Splitting
char **string_split(const char *str, const char *delimiter, size_t *count);
void free_string_array(char **array, size_t count);

// String Search & Compare
char *string_find(const char *haystack, const char *needle);
int string_compare(const char *a, const char *b);
int string_compare_case_insensitive(const char *a, const char *b);
int string_starts_with(const char *str, const char *prefix);
int string_ends_with(const char *str, const char *suffix);
int string_contains(const char *str, const char *substr);

// String Conversion
int string_to_int(const char *str);
float string_to_float(const char *str);
double string_to_double(const char *str);
void int_to_string(int value, char *buffer, size_t size);
void float_to_string(float value, char *buffer, size_t size);
void double_to_string(double value, char *buffer, size_t size);

// Basic Checks
int string_is_empty(const char *str);
int string_is_null(const char *str);
int string_is_not_null(const char *str);
int string_is_not_empty(const char *str);
int string_is_empty_or_whitespace(const char *str);
int string_is_not_empty_or_whitespace(const char *str);

// Character Checks
int string_is_numeric(const char *str);
int string_is_alpha(const char *str);
int string_is_alphanumeric(const char *str);
int string_is_space(const char *str);
int string_is_digit(const char *str);
int string_is_lower(const char *str);
int string_is_upper(const char *str);
int string_is_printable(const char *str);
int string_is_control(const char *str);
int string_is_graph(const char *str);
int string_is_blank(const char *str);
int string_is_cntrl(const char *str);
int string_is_punct(const char *str);

// Case/Grammar Checks
int string_is_title(const char *str);
int string_is_title_case(const char *str);

// SAFE-Varianten (Ergebnis per Pointer)
void string_is_empty_safe(const char *str, int *result);
void string_is_null_safe(const char *str, int *result);
void string_is_not_null_safe(const char *str, int *result);
void string_is_not_empty_safe(const char *str, int *result);
void string_is_empty_or_whitespace_safe(const char *str, int *result);
void string_is_not_empty_or_whitespace_safe(const char *str, int *result);
void string_is_numeric_safe(const char *str, int *result);
void string_is_alpha_safe(const char *str, int *result);
void string_is_alphanumeric_safe(const char *str, int *result);
void string_is_space_safe(const char *str, int *result);
void string_is_digit_safe(const char *str, int *result);
void string_is_lower_safe(const char *str, int *result);
void string_is_upper_safe(const char *str, int *result);
void string_is_printable_safe(const char *str, int *result);
void string_is_control_safe(const char *str, int *result);
void string_is_graph_safe(const char *str, int *result);
void string_is_blank_safe(const char *str, int *result);
void string_is_cntrl_safe(const char *str, int *result);
void string_is_punct_safe(const char *str, int *result);
void string_is_title_safe(const char *str, int *result);
void string_is_title_case_safe(const char *str, int *result);

// Spezialfunktionen
void string_is_grammatical(const char *str, int *result);
void string_is_anagram_switch(const char *str, int *result);

#endif