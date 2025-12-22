#pragma once

typedef struct sortedList {
    int value;
    struct sortedList* next;
} sortedList;

void add(sortedList** head, int value);
void dell(sortedList** head, int value);
void printList(sortedList* head);
void freeList(sortedList** head);