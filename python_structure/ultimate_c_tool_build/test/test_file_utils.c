// Test file for test_file_utils.c
#include <stdio.h>
#include "../include/file_utils.h"

int main(void) {
    printf("== File Utils Tests ==\n");
    const char *fname = "test_file_utils.c";
    printf("File '%s' exists? %d\n", fname, file_exists(fname));
    printf("File '%s' size: %zu\n", fname, file_size(fname));
    printf("All file_utils tests done!\n");
    return 0;
}
