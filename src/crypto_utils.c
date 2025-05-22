#include "../include/crypto_utils.h"
#include <openssl/sha.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/aes.h>  // Für AES_KEY und AES_encrypt
#include <openssl/evp.h>  // Für EVP_MD
#include <string.h>


int sha256_hash(const char *input, unsigned char *output, size_t out_size) {
    if (!input || !output || out_size < SHA256_DIGEST_LENGTH) return 0;
    if (!SHA256((const unsigned char *)input, strlen(input), output)) return 0;
    return 1;
}