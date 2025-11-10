#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void add(Node **head, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || value < (*head)->value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->value < value)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

void deleteValue(Node **head, int value) {
    if (*head == NULL) {
        printf("Список пуст.\n");
        return;
    }

    Node *temp = *head;
    if (temp->value == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node *prev = NULL;
    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Элемент %d не найден.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(Node *head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return;
    }
    printf("Список: ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
