#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

void add(sortedList** head, int value)
{
    sortedList* sList = malloc(sizeof(sortedList));
    if (!sList)
        return;
    sList->value = value;
    sList->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        sList->next = *head;
        *head = sList;
        return;
    }

    sortedList* current = *head;

    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    sList->next = current->next;
    current->next = sList;
}

void dell(sortedList** head, int value)
{
    if (*head == NULL)
        return;

    sortedList* temp = *head;
    sortedList* prev = NULL;

    if (temp != NULL && temp->value == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void printList(sortedList* head)
{
    printf("Сортированный список: ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
}

void freeList(sortedList** head)
{
    sortedList* current = *head;
    sortedList* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}