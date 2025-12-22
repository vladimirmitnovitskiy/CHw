#pragma once

#include <stdbool.h>

typedef struct StackNode{
    int value;
    struct StackNode* next;
} StackNode;

typedef struct{
    StackNode* head;
}Stack;

Stack* initStack();
void push(Stack* stack, int value);
bool isEmpty(Stack* stack);
int pop(Stack* stack);
void deleteStack(Stack* stack);
int peek(Stack* stack);