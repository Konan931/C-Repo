#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <stddef.h>

int sha256_hash(const char *input, unsigned char *output, size_t out_size);

#endif