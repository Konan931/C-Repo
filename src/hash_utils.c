#include "../include/hash_utils.h"
#include <openssl/sha.h>
#include <openssl/md5.h>

// djb2 hash function
unsigned long djb2(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}

// FNV-1a hash function
unsigned long fnv1a(const char *str) {
    unsigned long hash = 14695981039346656037UL;
    while (*str) {
        hash ^= (unsigned char)*str++;
        hash *= 1099511628211UL;
    }
    return hash;
}

// SDBM hash function
unsigned long sdbm(const char *str) {
    unsigned long hash = 0;
    int c;
    while ((c = *str++))
        hash = c + (hash << 6) + (hash << 16) - hash; // hash * 65599 + c
    return hash;
}
// ELF hash function
unsigned long elf(const char *str) {
    unsigned long hash = 0;
    int c;
    while ((c = *str++)) {
        hash = (hash << 4) + c;
        unsigned long x = hash & 0xF0000000L;
        if (x) {
            hash ^= x >> 24;
        }
        hash &= ~x;
    }
    return hash;
}

// Jenkins hash function
unsigned long jenkins(const char *str) {
    unsigned long hash = 0;
    while (*str) {
        hash += (unsigned char)*str++;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

// MurmurHash3 hash function
unsigned long murmur3(const char *str) {
    unsigned long hash = 0;
    const int len = strlen(str);
    const int nblocks = len / 4;
    const unsigned long c1 = 0xcc9e2d51;
    const unsigned long c2 = 0x1b873593;
    const unsigned long r1 = 15;
    const unsigned long r2 = 13;
    const unsigned long m = 5;
    const unsigned long n = 0xe6546b64;

    for (int i = 0; i < nblocks; i++) {
        unsigned long k = *(unsigned long *)(str + i * 4);
        k *= c1;
        k = (k << r1) | (k >> (32 - r1));
        k *= c2;

        hash ^= k;
        hash = (hash << r2) | (hash >> (32 - r2));
        hash = hash * m + n;
    }

    // Handle remaining bytes
    unsigned long k = 0;
    switch (len & 3) {
        case 3: k ^= ((unsigned char)str[len - 3]) << 16;
        case 2: k ^= ((unsigned char)str[len - 2]) << 8;
        case 1: k ^= ((unsigned char)str[len - 1]);
                k *= c1; k = (k << r1) | (k >> (32 - r1)); k *= c2; hash ^= k;
    }

    hash ^= len;
    hash ^= hash >> 16;
    hash *= 0x85ebca6b;
    hash ^= hash >> 13;
    hash *= 0xc2b2ae35;
    hash ^= hash >> 16;

    return hash;
}
// CRC32 hash function
unsigned long crc32(const char *str) {
    unsigned long crc = 0xFFFFFFFF;
    while (*str) {
        crc ^= (unsigned char)*str++;
        for (int i = 0; i < 8; i++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc >>= 1;
            }
        }
    }
    return ~crc;
}
// Hash function using SHA256
unsigned long hash_sha256(const char *str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)str, strlen(str), hash);
    unsigned long result = 0;
    for (int i = 0; i < sizeof(hash); i++) {
        result = (result << 8) | hash[i];
    }
    return result;
}
// Hash function using MD5
unsigned long hash_md5(const char *str) {
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)str, strlen(str), hash);
    unsigned long result = 0;
    for (int i = 0; i < sizeof(hash); i++) {
        result = (result << 8) | hash[i];
    }
    return result;
}
// Hash function using SHA1
unsigned long hash_sha1(const char *str) {
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((unsigned char *)str, strlen(str), hash);
    unsigned long result = 0;
    for (int i = 0; i < sizeof(hash); i++) {
        result = (result << 8) | hash[i];
    }
    return result;
}
// Hash function using SHA512
unsigned long hash_sha512(const char *str) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512((unsigned char *)str, strlen(str), hash);
    unsigned long result = 0;
    for (int i = 0; i < sizeof(hash); i++) {
        result = (result << 8) | hash[i];
    }
    return result;
}

