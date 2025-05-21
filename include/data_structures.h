#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct {
    int *data;
    int size;
} IntArray;

void int_array_init(IntArray *arr, int size);
void int_array_free(IntArray *arr);

#endif