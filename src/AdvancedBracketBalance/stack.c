#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

Stack* initStack()
{
    Stack* stack = malloc(sizeof(Stack));
    stack -> head = NULL;
    return stack;
}

void push(Stack* stack, int value)
{
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode -> value = value;
    newNode -> next = stack -> head;
    stack -> head = newNode;
}

bool isEmpty(Stack* stack)
{
    return stack -> head == NULL;
}

int pop(Stack* stack)
{
    if (isEmpty(stack)) return -1;

    StackNode* currentNode = stack -> head;
    int value = currentNode -> value;
    stack -> head = currentNode -> next;
    free(currentNode);
    return value;
}

void deleteStack(Stack* stack)
{
    while(stack -> head !=  NULL){
        pop(stack);
    }
    free(stack);
}

int peek(Stack* stack)
{
    if (isEmpty(stack)) return -1;

    return stack -> head -> value;
}