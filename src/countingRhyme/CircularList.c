#include "CircularList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node* next;
} Node;

struct CircularList{
    Node* tail;
};

Node* initNode(int id)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

CircularList* initCircularList(int n)
{
    CircularList* circle = malloc(sizeof(CircularList));
    if (!circle){
        return NULL;
    }

    if (n <= 0) {
        circle->tail = NULL;
        return circle;
    }

    Node* head = initNode(1);
    Node* prev = head;

    for (int i = 2; i <= n; i++) {
        Node* newNode = initNode(i);
        prev->next = newNode;
        prev = newNode;
    }

    prev->next = head;
    circle->tail = prev;

    return circle;
}

int kill(CircularList* circle, int m)
{   
    if (!circle || !circle->tail)
        return 0;
    if (m <= 0)
        return 0;

    Node* current = circle->tail;

    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            current = current->next;
        }

        Node* victim = current->next;
        current->next = victim->next;

        free(victim);
    }

    int survivorId = current->id;
    
    free(current);
    free(circle);

    return survivorId;
}