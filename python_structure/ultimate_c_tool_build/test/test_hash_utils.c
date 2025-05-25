// Test file for test_hash_utils.c

#include <stdio.h>
#include <string.h>
#include "../include/hash_utils.h"

int main(void) {
    printf("== Hash Utils Tests ==\n");
    char output[16];
    simple_hash("test", output, sizeof(output));
    printf("Simple hash: ");
    for (size_t i = 0; i < sizeof(output); ++i)
        printf("%02x", (unsigned char)output[i]);
    printf("\n");
    printf("All hash_utils tests done!\n");
    return 0;
}
