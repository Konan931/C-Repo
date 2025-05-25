#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hex_octal_utils.h"

int main(void) {
    printf("== Hex/Octal Utils Tests ==\n");

    char hexbuf[32], octbuf[32];

    // int zu Hex/Octal
    int_to_hex(255, hexbuf, sizeof(hexbuf));
    int_to_octal(255, octbuf, sizeof(octbuf));
    printf("255 in hex: %s, in octal: %s\n", hexbuf, octbuf);

    // Dezimal zu Hex/Octal
    decimal_to_hex(123456, hexbuf, sizeof(hexbuf));
    decimal_to_octal(123456, octbuf, sizeof(octbuf));
    printf("123456 in hex: %s, in octal: %s\n", hexbuf, octbuf);

    // Hex/Octal/Binär zu Dezimal
    printf("Hex 'FF' to decimal: %d\n", hex_to_decimal("FF"));
    printf("Octal '377' to decimal: %d\n", octal_to_decimal("377"));
    printf("Binary '11111111' to decimal: %d\n", binary_to_decimal("11111111"));

    // Hex/Octal zu int/float/double
    printf("Hex 'FF' to int: %d\n", hex_to_int("FF"));
    printf("Octal '377' to int: %d\n", octal_to_int("377"));
    printf("Hex 'FF' to float: %f\n", hex_to_float("FF"));
    printf("Octal '377' to float: %f\n", octal_to_float("377"));
    printf("Hex 'FF' to double: %lf\n", hex_to_double("FF"));
    printf("Octal '377' to double: %lf\n", octal_to_double("377"));

    // Hex/Octal zu String
    char *hexstr = hex_to_string("FF");
    char *octstr = octal_to_string("377");
    printf("Hex 'FF' to string: %s\n", hexstr);
    printf("Octal '377' to string: %s\n", octstr);
    free(hexstr);
    free(octstr);

    // Hex/Octal zu Binär-String
    char *hexbin = hex_to_binary("FF");
    char *octbin = octal_to_binary("377");
    printf("Hex 'FF' to binary: %s\n", hexbin);
    printf("Octal '377' to binary: %s\n", octbin);
    free(hexbin);
    free(octbin);

    // Typkonvertierungen
    printf("Hex 'FF' to unsigned int: %u\n", hex_to_binary_uint("FF"));
    printf("Octal '377' to unsigned int: %u\n", octal_to_binary_uint("377"));
    printf("Hex 'FF' to long: %ld\n", hex_to_binary_long("FF"));
    printf("Octal '377' to long: %ld\n", octal_to_binary_long("377"));
    printf("Hex 'FF' to unsigned long: %lu\n", hex_to_binary_ulong("FF"));
    printf("Octal '377' to unsigned long: %lu\n", octal_to_binary_ulong("377"));
    printf("Hex 'FF' to int8_t: %d\n", hex_to_binary_int8("FF"));
    printf("Octal '377' to int8_t: %d\n", octal_to_binary_int8("377"));
    printf("Hex 'FF' to uint8_t: %u\n", hex_to_binary_uint8("FF"));
    printf("Octal '377' to uint8_t: %u\n", octal_to_binary_uint8("377"));

    // Hex/ASCII-Konvertierung
    char *ascii = hex_to_ascii("48656c6c6f21");
    printf("Hex to ASCII: %s\n", ascii);
    char *hex = ascii_to_hex("Hello!");
    printf("ASCII to Hex: %s\n", hex);
    free(ascii);
    free(hex);

    printf("All hex_octal_utils tests done!\n");
    return 0;
}