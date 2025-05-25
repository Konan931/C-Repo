#ifndef HEX_OCTAL_UTILS_H
#define HEX_OCTAL_UTILS_H

#include <stddef.h>
#include <stdint.h>

// Integer zu Hex/Octal-String
void int_to_hex(int value, char *buffer, size_t bufsize);
void int_to_octal(int value, char *buffer, size_t bufsize);

// Dezimal zu Hex/Octal-String (unsigned long für große Werte)
void decimal_to_hex(unsigned long value, char *buffer, size_t bufsize);
void decimal_to_octal(unsigned long value, char *buffer, size_t bufsize);

// Hex/Octal/Binär zu Dezimal
int hex_to_decimal(const char *hex);
int octal_to_decimal(const char *octal);
int binary_to_decimal(const char *binary);

// Hex/Octal zu int/float/double
int hex_to_int(const char *hex);
int octal_to_int(const char *octal);
float hex_to_float(const char *hex);
float octal_to_float(const char *octal);
double hex_to_double(const char *hex);
double octal_to_double(const char *octal);

// Hex/Octal zu String (liefert neuen String, muss mit free() freigegeben werden)
char *hex_to_string(const char *hex);
char *octal_to_string(const char *octal);

// Hex/Octal zu Binär-String (liefert neuen String, muss mit free() freigegeben werden)
char *hex_to_binary(const char *hex);
char *octal_to_binary(const char *octal);

// Hex/Octal zu Binär als verschiedene Typen
int hex_to_binary_int(const char *hex);
int octal_to_binary_int(const char *octal);
unsigned int hex_to_binary_uint(const char *hex);
unsigned int octal_to_binary_uint(const char *octal);
long hex_to_binary_long(const char *hex);
long octal_to_binary_long(const char *octal);
unsigned long hex_to_binary_ulong(const char *hex);
unsigned long octal_to_binary_ulong(const char *octal);
long long hex_to_binary_longlong(const char *hex);
long long octal_to_binary_longlong(const char *octal);
unsigned long long hex_to_binary_ulonglong(const char *hex);
unsigned long long octal_to_binary_ulonglong(const char *octal);
short hex_to_binary_short(const char *hex);
short octal_to_binary_short(const char *octal);
unsigned short hex_to_binary_ushort(const char *hex);
unsigned short octal_to_binary_ushort(const char *octal);
char hex_to_binary_char(const char *hex);
char octal_to_binary_char(const char *octal);
unsigned char hex_to_binary_uchar(const char *hex);
unsigned char octal_to_binary_uchar(const char *octal);
int8_t hex_to_binary_int8(const char *hex);
int8_t octal_to_binary_int8(const char *octal);
uint8_t hex_to_binary_uint8(const char *hex);
uint8_t octal_to_binary_uint8(const char *octal);
int16_t hex_to_binary_int16(const char *hex);
int16_t octal_to_binary_int16(const char *octal);
uint16_t hex_to_binary_uint16(const char *hex);
uint16_t octal_to_binary_uint16(const char *octal);
int32_t hex_to_binary_int32(const char *hex);
int32_t octal_to_binary_int32(const char *octal);
uint32_t hex_to_binary_uint32(const char *hex);
uint32_t octal_to_binary_uint32(const char *octal);
int64_t hex_to_binary_int64(const char *hex);
int64_t octal_to_binary_int64(const char *octal);
uint64_t hex_to_binary_uint64(const char *hex);
uint64_t octal_to_binary_uint64(const char *octal);
size_t hex_to_binary_size_t(const char *hex);
size_t octal_to_binary_size_t(const char *octal);
ptrdiff_t hex_to_binary_ptrdiff_t(const char *hex);
ptrdiff_t octal_to_binary_ptrdiff_t(const char *octal);
intptr_t hex_to_binary_intptr_t(const char *hex);
intptr_t octal_to_binary_intptr_t(const char *octal);
uintptr_t hex_to_binary_uintptr_t(const char *hex);
uintptr_t octal_to_binary_uintptr_t(const char *octal);

// Hex/ASCII-Konvertierung
char *hex_to_ascii(const char *hex);
char *ascii_to_hex(const char *ascii);

#endif