#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

struct Stack {
    StackNode* head;
};

Stack* initStack()
{
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* stack, int value)
{
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode->value = value;
    newNode->next = stack->head;
    stack->head = newNode;
}

bool isEmpty(Stack* stack)
{
    return stack->head == NULL;
}

int pop(Stack* stack)
{
    StackNode* currentNode = stack->head;
    int value = currentNode->value;
    stack->head = currentNode->next;
    free(currentNode);
    return value;
}

void deleteStack(Stack* stack)
{
    while (stack->head != NULL) {
        pop(stack);
    }
    free(stack);
}

int peek(Stack* stack)
{
    return stack->head->value;
}
