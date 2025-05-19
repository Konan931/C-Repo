#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

void safe_concat(char *dest, const char *src, size_t size);
size_t custom_strlen(const char *str);

// Copies src to dest, ensuring no overflow occurs and null-terminates the destination (dest), maximum size-1 bytes are copied (including null terminator)
// Returns the number of bytes copied (excluding null terminator)
size_t custom_strcpy(char *dest, const char *src, size_t size);
// Copies src to dest, ensuring no overflow occurs and null-terminates the destination (dest), maximum size-1 bytes are copied (including null terminator)
// Returns the number of bytes copied (excluding null terminator)
size_t custom_strncpy(char *dest, const char *src, size_t size);
// Copies src to dest, ensuring no overflow occurs and null-terminates the destination (dest), maximum size-1 bytes are copied (including null terminator)
// Returns the number of bytes copied (excluding null terminator)
size_t custom_strcat(char *dest, const char *src, size_t size);
// Copies src to dest, ensuring no overflow occurs and null-terminates the destination (dest), maximum size-1 bytes are copied (including null terminator)
// Returns the number of bytes copied (excluding null terminator)
size_t custom_strncat(char *dest, const char *src, size_t size);
size_t custom_strcmp(const char *str1, const char *str2);
size_t custom_strncmp(const char *str1, const char *str2, size_t n);
size_t custom_strchr(const char *str, int c);
size_t custom_strrchr(const char *str, int c);
size_t custom_strstr(const char *haystack, const char *needle);
size_t custom_strtok(char *str, const char *delim);
// Splits a string into tokens based on a delimiter
// Returns the number of tokens found
size_t custom_strsplit(const char *str, const char *delim, char **tokens, size_t max_tokens);
size_t custom_strrev(char *str);
// Reverses a string in place
// Returns the length of the reversed string
size_t custom_strrev(char *str);
size_t custom_str2int(const char *str);
size_t custom_int2str(int value, char *buffer, size_t size);
size_t custom_str2binary(const char *str);
// Converts a binary string to an unsigned integer
// Returns the unsigned integer value
// Returns 0 on success, -1 on failure
size_t custom_binary2str(unsigned int value, char *buffer, size_t size);
size_t custom_str2base64(const char *str);
void safe_copy(char *dest, const char *src, size_t size);
size_t custom_binary2str(unsigned int value, char *buffer, size_t size);
size_t custom_base642str(const char *base64_str);
size_t custom_base64_encode(const char *str);
size_t custom_base64_decode(const char *base64_str);
size_t custom_base64_url_encode(const char *str);
size_t custom_base64_url_decode(const char *base64_str);
// Encodes a string to Base64 URL safe format
// Returns the length of the encoded string
// Returns 0 on success, -1 on failure
size_t custom_base64_url_safe_encode(const char *str);
size_t custom_base64_url_safe_decode(const char *base64_str);
int string_compare(const char *str1, const char *str2);
const char *string_find(const char *haystack, const char *needle);
int string_split(const char *str, char delimiter, char **tokens, int max_tokens);
void string_reverse(char *str);
int string_to_int(const char *str);
void int_to_string(int value, char *buffer, size_t size);
int string_to_binary(const char *str);
void binary_to_string(unsigned int value, char *buffer, size_t size);
char *string_to_base64(const char *str);
char *base64_to_string(const char *base64_str);
char *base64_encode(const char *str);
char *base64_decode(const char *base64_str);
char *base64_url_encode(const char *str);
char *base64_url_decode(const char *base64_str);
char *base64_url_safe_encode(const char *str);
char *base64_url_safe_decode(const char *base64_str);

// String copy with overflow check
char* safe_strcpy(char *dest, const char *src, size_t n);

// Concatenate two strings with overflow check
char* safe_strcat(char *dest, const char *src, size_t n);

// String reverse
void reverse_string(char *str);

#endif
