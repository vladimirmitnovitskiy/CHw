#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(const char *expr)
{
    Stack stack;
    init(&stack);

    int i = 0;
    int len = strlen(expr);

    while (i < len) {
        char c = expr[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (isdigit(c)) {
            while (i < len && (isdigit(expr[i]) || expr[i] == '.')) {
                printf("%c", expr[i]);
                i++;
            }
            printf(" ");
            continue;
        }

        if (c == '(') {
            push(&stack, c);
        }

        else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("%c ", pop(&stack));
            }
            if (!isEmpty(&stack) && peek(&stack) == '(')
                pop(&stack);
        }

        else if (isOperator(c)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(c)) {
                printf("%c ", pop(&stack));
            }
            push(&stack, c);
        }

        i++;
    }

    while (!isEmpty(&stack)) {
        printf("%c ", pop(&stack));
    }

    printf("\n");
}
