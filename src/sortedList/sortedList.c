#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Initializes a new empty sorted list.
 *
 * Allocates memory for the SortedList structure and initializes its
 * head pointer to NULL.
 *
 * @return A pointer to the newly created SortedList, or NULL if memory allocation fails.
 */
SortedList* initList()
{
    SortedList* sList = malloc(sizeof(SortedList));
    if (sList){
        sList -> head = NULL;
    }
    return sList;
}

/**
 * @brief Adds a value to the list while maintaining sorted order.
 *
 * Creates a new node with the given value and inserts it into the correct
 * position in the list so that the list remains sorted (ascending order).
 *
 * @param sList Pointer to the sorted list.
 * @param value The integer value to add.
 * @return true if the value was successfully added; false otherwise (e.g., memory allocation failure).
 */
bool add(SortedList* sList, int value)
{
    Num* newNum = malloc(sizeof(Num));
    if (!newNum) return false;
    newNum -> value = value;

    if (sList -> head == NULL || sList -> head -> value >= value){
        newNum -> next = sList -> head;
        sList -> head = newNum;
        return true;
    }

    Num* current = sList -> head;
    while (current -> next != NULL && current -> next -> value < value){
        current = current -> next;
    }

    newNum -> next = current ->next;
    current -> next = newNum;
    return true;
}

/**
 * @brief Deletes a specific value from the list.
 *
 * Searches for the first occurrence of the specified value in the list
 * and removes it. Frees the memory associated with the removed node.
 *
 * @param sList Pointer to the sorted list.
 * @param value The integer value to remove.
 * @return true if the value was found and deleted; false if the value was not found in the list.
 */
bool deleteByValue(SortedList* sList, int value)
{
    if (sList == NULL || sList->head == NULL) return false;

    Num* temp = sList->head;
    Num* prev = NULL;


    if (temp != NULL && temp->value == value) {
        sList->head = temp->next;
        free(temp);
        return true;
    }


    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return false;

    prev->next = temp->next;
    free(temp);
    return true;
}

/**
 * @brief Prints the contents of the list to the standard output.
 *
 * Traverses the list from head to tail and prints each value.
 * If the list is empty, it may print a specific message or nothing.
 *
 * @param sList Pointer to the sorted list to print.
 */
void printList(SortedList* sList)
{
    if (sList == NULL) return;
    Num* current = sList->head;
    printf("Список: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

/**
 * @brief Frees all memory associated with the list.
 *
 * Iterates through the list to free every node, and finally frees
 * the SortedList structure itself. After calling this, the sList pointer
 * is invalid.
 *
 * @param sList Pointer to the sorted list to delete.
 */
void freeList(SortedList* sList)
{
    if (sList == NULL) return;

    Num* current = sList->head;
    Num* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(sList);
}