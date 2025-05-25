#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <stddef.h>

// Include necessary headers for SHA256 and Base64
int sha256_hash(const char *input, unsigned char *output, size_t out_size);
int sha256_hash_safe(const char *input, unsigned char *output, size_t out_size);

// Base64 encoding and decoding
char *base64_encode(const char *input);
char *base64_decode(const char *input);

// Hexadecimal to binary conversion
unsigned char hex_to_binary_uint8(const char *hex_str);

// Endian conversion
unsigned int swap_endian_uint32(unsigned int value);
unsigned short swap_endian_uint16(unsigned short value);


#endif