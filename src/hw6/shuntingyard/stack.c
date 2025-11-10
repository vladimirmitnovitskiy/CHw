#include "stack.h"

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    return s->data[s->top--];
}

char peek(Stack *s) {
    return s->data[s->top];
}
