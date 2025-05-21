// Source file for data_structures.c
#include "../include/data_structures.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

void int_array_init(IntArray *arr, int size) {
    arr->data = malloc(size * sizeof(int));
    arr->size = size;
}
void int_array_free(IntArray *arr) {
    if (arr->data) free(arr->data);
    arr->data = NULL;
    arr->size = 0;
}