#ifndef FUNCS_H
#define FUNCS_H

#include <stddef.h>

typedef struct {
    int* array;
    size_t used;
    size_t size;
} Array;

void initArray(Array* a, size_t initialSize);
void insertArray(Array* a, int element);
void freeArray(Array* a);
void removeZero(Array* a);

#endif