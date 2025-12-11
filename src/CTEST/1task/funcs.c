#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initArray(Array* a, size_t initialSize)
{
    a->array = (int*)malloc(initialSize * sizeof(int));
    if (a->array == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array* a, int element)
{
    if (a->used == a->size) {
        size_t newSize = (a->size == 0) ? 1 : a->size * 2;

        int* temp = (int*)realloc(a->array, newSize * sizeof(int));
        if (temp == NULL) {
            fprintf(stderr, "Ошибка перевыделения памяти\n");
            free(a->array);
            exit(1);
        }

        a->array = temp;
        a->size = newSize;
    }

    a->array[a->used++] = element;
}

void freeArray(Array* a)
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void removeZero(Array* a)
{
    size_t writer = 0;

    for (size_t reader = 0; reader < a->used; reader++) {
        if (a->array[reader] != 0) {
            a->array[writer] = a->array[reader];
            writer++;
        }
    }
    a->used = writer;
}