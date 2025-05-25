// Test file for test_data_structures.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "../include/data_structures.h"
// Make sure IntArray is defined in data_structures.h, or define it here if missing
#ifndef INTARRAY_DEFINED
#define INTARRAY_DEFINED
typedef struct {
    int *data;
    size_t size;
} IntArray;
#endif

int main(void) {
    printf("== Data Structures Tests ==\n");
    IntArray arr;
    int_array_init(&arr, 3);
    for (int i = 0; i < arr.size; ++i) arr.data[i] = i * 2;
    printf("IntArray: ");
    for (int i = 0; i < arr.size; ++i) printf("%d ", arr.data[i]);
    printf("\n");
    int_array_free(&arr);
    printf("All data_structures tests done!\n");
    return 0;
}
