// Test file for test_debug_utils.c
#include <stdio.h>
#include "../include/debug_utils.h"

int main(void) {
    printf("== Debug Utils Tests ==\n");
    trace("This is a debug trace!");
    printf("All debug_utils tests done!\n");
    return 0;
}
