#include "../include/hex_octal_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

// Hilfsfunktion: Hex-Zeichen zu Wert
static int hex_char_to_val(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    return -1;
}

// Integer zu Hex/Octal-String
void int_to_hex(int value, char *buffer, size_t bufsize) {
    snprintf(buffer, bufsize, "%x", value);
}
void int_to_octal(int value, char *buffer, size_t bufsize) {
    snprintf(buffer, bufsize, "%o", value);
}

// Dezimal zu Hex/Octal-String
void decimal_to_hex(unsigned long value, char *buffer, size_t bufsize) {
    snprintf(buffer, bufsize, "%lX", value);
}
void decimal_to_octal(unsigned long value, char *buffer, size_t bufsize) {
    snprintf(buffer, bufsize, "%lo", value);
}

// Hex/Octal/Binär zu Dezimal
int hex_to_decimal(const char *hex) {
    int value = 0;
    sscanf(hex, "%x", &value);
    return value;
}
int octal_to_decimal(const char *octal) {
    int value = 0;
    sscanf(octal, "%o", &value);
    return value;
}
int binary_to_decimal(const char *binary) {
    int value = 0;
    while (*binary) {
        value = value * 2 + (*binary++ - '0');
    }
    return value;
}

// Hex/Octal zu int/float/double
int hex_to_int(const char *hex) { return (int)strtol(hex, NULL, 16); }
int octal_to_int(const char *octal) { return (int)strtol(octal, NULL, 8); }
float hex_to_float(const char *hex) { return (float)strtol(hex, NULL, 16); }
float octal_to_float(const char *octal) { return (float)strtol(octal, NULL, 8); }
double hex_to_double(const char *hex) { return (double)strtol(hex, NULL, 16); }
double octal_to_double(const char *octal) { return (double)strtol(octal, NULL, 8); }

// Hex/Octal zu String (liefert neuen String)
char *hex_to_string(const char *hex) {
    int val = hex_to_int(hex);
    char *str = malloc(32);
    if (str) snprintf(str, 32, "%d", val);
    return str;
}
char *octal_to_string(const char *octal) {
    int val = octal_to_int(octal);
    char *str = malloc(32);
    if (str) snprintf(str, 32, "%d", val);
    return str;
}

// Hex/Octal zu Binär-String (liefert neuen String)
char *hex_to_binary(const char *hex) {
    int val = hex_to_int(hex);
    char *bin = malloc(33);
    if (!bin) return NULL;
    for (int i = 31; i >= 0; --i)
        bin[31 - i] = ((val >> i) & 1) ? '1' : '0';
    bin[32] = '\0';
    return bin;
}
char *octal_to_binary(const char *octal) {
    int val = octal_to_int(octal);
    char *bin = malloc(33);
    if (!bin) return NULL;
    for (int i = 31; i >= 0; --i)
        bin[31 - i] = ((val >> i) & 1) ? '1' : '0';
    bin[32] = '\0';
    return bin;
}

// Verschiedene Typen (hier als Beispiel, alle anderen analog)
int hex_to_binary_int(const char *hex) { return hex_to_int(hex); }
int octal_to_binary_int(const char *octal) { return octal_to_int(octal); }
unsigned int hex_to_binary_uint(const char *hex) { return (unsigned int)strtoul(hex, NULL, 16); }
unsigned int octal_to_binary_uint(const char *octal) { return (unsigned int)strtoul(octal, NULL, 8); }
long hex_to_binary_long(const char *hex) { return strtol(hex, NULL, 16); }
long octal_to_binary_long(const char *octal) { return strtol(octal, NULL, 8); }
unsigned long hex_to_binary_ulong(const char *hex) { return strtoul(hex, NULL, 16); }
unsigned long octal_to_binary_ulong(const char *octal) { return strtoul(octal, NULL, 8); }
long long hex_to_binary_longlong(const char *hex) { return strtoll(hex, NULL, 16); }
long long octal_to_binary_longlong(const char *octal) { return strtoll(octal, NULL, 8); }
unsigned long long hex_to_binary_ulonglong(const char *hex) { return strtoull(hex, NULL, 16); }
unsigned long long octal_to_binary_ulonglong(const char *octal) { return strtoull(octal, NULL, 8); }
short hex_to_binary_short(const char *hex) { return (short)strtol(hex, NULL, 16); }
short octal_to_binary_short(const char *octal) { return (short)strtol(octal, NULL, 8); }
unsigned short hex_to_binary_ushort(const char *hex) { return (unsigned short)strtoul(hex, NULL, 16); }
unsigned short octal_to_binary_ushort(const char *octal) { return (unsigned short)strtoul(octal, NULL, 8); }
char hex_to_binary_char(const char *hex) { return (char)strtol(hex, NULL, 16); }
char octal_to_binary_char(const char *octal) { return (char)strtol(octal, NULL, 8); }
unsigned char hex_to_binary_uchar(const char *hex) { return (unsigned char)strtoul(hex, NULL, 16); }
unsigned char octal_to_binary_uchar(const char *octal) { return (unsigned char)strtoul(octal, NULL, 8); }
int8_t hex_to_binary_int8(const char *hex) { return (int8_t)strtol(hex, NULL, 16); }
int8_t octal_to_binary_int8(const char *octal) { return (int8_t)strtol(octal, NULL, 8); }
uint8_t hex_to_binary_uint8(const char *hex) { return (uint8_t)strtoul(hex, NULL, 16); }
uint8_t octal_to_binary_uint8(const char *octal) { return (uint8_t)strtoul(octal, NULL, 8); }
int16_t hex_to_binary_int16(const char *hex) { return (int16_t)strtol(hex, NULL, 16); }
int16_t octal_to_binary_int16(const char *octal) { return (int16_t)strtol(octal, NULL, 8); }
uint16_t hex_to_binary_uint16(const char *hex) { return (uint16_t)strtoul(hex, NULL, 16); }
uint16_t octal_to_binary_uint16(const char *octal) { return (uint16_t)strtoul(octal, NULL, 8); }
int32_t hex_to_binary_int32(const char *hex) { return (int32_t)strtol(hex, NULL, 16); }
int32_t octal_to_binary_int32(const char *octal) { return (int32_t)strtol(octal, NULL, 8); }
uint32_t hex_to_binary_uint32(const char *hex) { return (uint32_t)strtoul(hex, NULL, 16); }
uint32_t octal_to_binary_uint32(const char *octal) { return (uint32_t)strtoul(octal, NULL, 8); }
int64_t hex_to_binary_int64(const char *hex) { return (int64_t)strtoll(hex, NULL, 16); }
int64_t octal_to_binary_int64(const char *octal) { return (int64_t)strtoll(octal, NULL, 8); }
uint64_t hex_to_binary_uint64(const char *hex) { return (uint64_t)strtoull(hex, NULL, 16); }
uint64_t octal_to_binary_uint64(const char *octal) { return (uint64_t)strtoull(octal, NULL, 8); }
size_t hex_to_binary_size_t(const char *hex) { return (size_t)strtoull(hex, NULL, 16); }
size_t octal_to_binary_size_t(const char *octal) { return (size_t)strtoull(octal, NULL, 8); }
ptrdiff_t hex_to_binary_ptrdiff_t(const char *hex) { return (ptrdiff_t)strtoll(hex, NULL, 16); }
ptrdiff_t octal_to_binary_ptrdiff_t(const char *octal) { return (ptrdiff_t)strtoll(octal, NULL, 8); }
intptr_t hex_to_binary_intptr_t(const char *hex) { return (intptr_t)strtoll(hex, NULL, 16); }
intptr_t octal_to_binary_intptr_t(const char *octal) { return (intptr_t)strtoll(octal, NULL, 8); }
uintptr_t hex_to_binary_uintptr_t(const char *hex) { return (uintptr_t)strtoull(hex, NULL, 16); }
uintptr_t octal_to_binary_uintptr_t(const char *octal) { return (uintptr_t)strtoull(octal, NULL, 8); }

// Hex/ASCII-Konvertierung
char *hex_to_ascii(const char *hex) {
    size_t len = strlen(hex);
    if (len % 2 != 0) return NULL;
    char *ascii = malloc(len / 2 + 1);
    if (!ascii) return NULL;
    for (size_t i = 0; i < len; i += 2) {
        int hi = hex_char_to_val(hex[i]);
        int lo = hex_char_to_val(hex[i + 1]);
        if (hi < 0 || lo < 0) {
            free(ascii);
            return NULL;
        }
        ascii[i / 2] = (char)((hi << 4) | lo);
    }
    ascii[len / 2] = '\0';
    return ascii;
}

char *ascii_to_hex(const char *ascii) {
    size_t len = strlen(ascii);
    char *hex = malloc(len * 2 + 1);
    if (!hex) return NULL;
    for (size_t i = 0; i < len; ++i) {
        sprintf(hex + i * 2, "%02x", (unsigned char)ascii[i]);
    }
    hex[len * 2] = '\0';
    return hex;
}

