#include "../include/crypto_utils.h"
#include <openssl/sha.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/aes.h>  // Für AES_KEY und AES_encrypt
#include <openssl/evp.h>  // Für EVP_MD
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <assert.h>


int sha256_hash(const char *input, unsigned char *output, size_t out_size) {
    if (!input || !output || out_size < SHA256_DIGEST_LENGTH) return 0;
    if (!SHA256((const unsigned char *)input, strlen(input), output)) return 0;
    return 1;
}

char *base64_encode(const char *input) {
    if (!input) return NULL;
    size_t input_len = strlen(input);
    size_t output_len = 4 * ((input_len + 2) / 3);
    char *output = (char *)malloc(output_len + 1);
    if (!output) return NULL;

    static const char base64_chars[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    for (size_t i = 0, j = 0; i < input_len;) {
        uint32_t octet_a = i < input_len ? (unsigned char)input[i++] : 0;
        uint32_t octet_b = i < input_len ? (unsigned char)input[i++] : 0;
        uint32_t octet_c = i < input_len ? (unsigned char)input[i++] : 0;

        uint32_t triple = (octet_a << 16) | (octet_b << 8) | octet_c;

        output[j++] = base64_chars[(triple >> 18) & 0x3F];
        output[j++] = base64_chars[(triple >> 12) & 0x3F];
        output[j++] = (i > input_len + 1) ? '=' : base64_chars[(triple >> 6) & 0x3F];
        output[j++] = (i > input_len) ? '=' : base64_chars[triple & 0x3F];
    }
    output[output_len] = '\0';
    return output;
}
char *base64_decode(const char *input) {
    if (!input) return NULL;
    size_t input_len = strlen(input);
    if (input_len % 4 != 0) return NULL;

    size_t output_len = input_len / 4 * 3;
    if (input[input_len - 1] == '=') output_len--;
    if (input[input_len - 2] == '=') output_len--;

    char *output = (char *)malloc(output_len + 1);
    if (!output) return NULL;

    static const char base64_chars[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    for (size_t i = 0, j = 0; i < input_len;) {
        uint32_t sextet_a = input[i] == '=' ? 0 : strchr(base64_chars, input[i]) - base64_chars;
        uint32_t sextet_b = input[i + 1] == '=' ? 0 : strchr(base64_chars, input[i + 1]) - base64_chars;
        uint32_t sextet_c = input[i + 2] == '=' ? 0 : strchr(base64_chars, input[i + 2]) - base64_chars;
        uint32_t sextet_d = input[i + 3] == '=' ? 0 : strchr(base64_chars, input[i + 3]) - base64_chars;

        uint32_t triple = (sextet_a << 18) | (sextet_b << 12) | (sextet_c << 6) | sextet_d;

        if (j < output_len) output[j++] = (triple >> 16) & 0xFF;
        if (j < output_len) output[j++] = (triple >> 8) & 0xFF;
        if (j < output_len) output[j++] = triple & 0xFF;

        i += 4;
    }
    output[output_len] = '\0';
    return output;
}

// Endian conversion functions
unsigned int swap_endian_uint32(unsigned int value) {
    return ((value >> 24) & 0x000000FF) |
           ((value << 8) & 0x00FF0000) |
           ((value >> 8) & 0x0000FF00) |
           ((value << 24) & 0xFF000000);
}
unsigned short swap_endian_uint16(unsigned short value) {
    return (value >> 8) | (value << 8);
}
