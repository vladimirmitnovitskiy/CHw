#include "CircularList.h"
#include <stdio.h>
#include <stdlib.h>

Node* initNode(int id)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

CircularList initCircularList(int n)
{
    CircularList circle = { NULL };

    Node* head = initNode(1);
    Node* prev = head;

    for (int i = 2; i <= n; i++) {
        Node* newNode = initNode(i);
        prev->next = newNode;
        prev = newNode;
    }

    prev->next = head;
    circle.tail = prev;

    return circle;
}