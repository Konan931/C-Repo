#include "../include/hex_octal_utils.h"
// Compare this snippet from ultimate_c_tool/src/hex_octal_utils.c:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void int_to_hex(int value, char *buffer, int bufsize) {
	snprintf(buffer, bufsize, "%x", value);
}

void int_to_octal(int value, char *buffer, int bufsize) {
	snprintf(buffer, bufsize, "%o", value);
}