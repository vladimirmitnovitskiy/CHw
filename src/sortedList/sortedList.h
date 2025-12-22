#pragma once

#include <stdbool.h>


typedef struct Num {
    int value;
    struct Num* next;
} Num;

typedef struct{
    Num* head;
} SortedList;


SortedList* initList();
bool add(SortedList* sList, int value);
bool deleteByValue(SortedList* sList, int value);
void printList(SortedList* sList);
void freeList(SortedList* sList);