#ifndef HASH_UTILS_H
#define HASH_UTILS_H

unsigned long djb2(const char *str);
unsigned long fnv1a(const char *str);
unsigned long sdbm(const char *str);
unsigned long elf(const char *str);
unsigned long fnv(const char *str);
unsigned long jenkins(const char *str);
unsigned long murmur(const char *str);
unsigned long crc32(const char *str);
unsigned long hash_djb2(const char *str);
unsigned long hash_sdbm(const char *str);
unsigned long hash_elf(const char *str);
unsigned long hash_fnv(const char *str);
unsigned long hash_jenkins(const char *str);
unsigned long hash_murmur(const char *str);
unsigned long hash_crc32(const char *str);
unsigned long hash(const char *str, unsigned long (*hash_func)(const char *));

// Hash test with SHA1
unsigned long hash_sha1(const char *str);
unsigned long hash_sha256(const char *str);

// Hash test with MD5
unsigned long hash_md5(const char *str);

// Hash test with SHA512
unsigned long hash_sha512(const char *str);

// Hash test with SHA...
unsigned long hash_sha384(const char *str);
unsigned long hash_sha224(const char *str);
unsigned long hash_sha1(const char *str);
unsigned long hash_sha256(const char *str);
unsigned long hash_sha512(const char *str);
unsigned long hash_sha384(const char *str);
unsigned long hash_sha224(const char *str);
unsigned long hash_sha3_224(const char *str);
unsigned long hash_sha3_256(const char *str);
unsigned long hash_sha3_384(const char *str);
unsigned long hash_sha3_512(const char *str);
unsigned long hash_blake2b(const char *str);
unsigned long hash_blake2s(const char *str);
unsigned long hash_bcrypt(const char *str);
unsigned long hash_pbkdf2(const char *str);
unsigned long hash_argon2(const char *str);
unsigned long hash_scrypt(const char *str);

#endif
