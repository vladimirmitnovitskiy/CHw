#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void add(Node **head, int value);
void deleteValue(Node **head, int value);
void printList(Node *head);
void freeList(Node *head);

#endif 
