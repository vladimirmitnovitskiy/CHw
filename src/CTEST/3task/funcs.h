#ifndef FUNCS_H
#define FUNCS_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value);
void append(Node** headRef, int value);
void freeList(Node* head);
Node* reverseList(Node* head);

#endif