#pragma once

typedef struct Node {
    int id;
    struct Node* next;
} Node;

typedef struct {
    Node* tail;
} CircularList;

Node* initNode(int n);
CircularList initCircularList(int n);