#include "stack.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

static bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

char* infixToPostfix(const char* str, int* errorCode)
{
    if (errorCode != NULL) {
        *errorCode = 0;
    }

    Stack* stack = initStack();
    int i = 0;
    int k = 0;
    char* postfix = malloc((2 * strlen(str) + 1) * sizeof(char));
    if (!postfix) {
        if (errorCode != NULL)
            *errorCode = 2; // 2 - ошибка выделения памяти
        deleteStack(stack);
        return NULL;
    }

    while (str[i] != '\0') {
        if (isspace(str[i])) {
            i++;
            continue;
        }

        if (isdigit(str[i])) {
            postfix[k++] = str[i];
            postfix[k++] = ' ';
        } else if (str[i] == '(') {
            push(stack, str[i]);
        }

        else if (str[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(stack);
                postfix[k++] = ' ';
            }

            if (!isEmpty(stack)) {
                pop(stack);
            } else {
                if (errorCode != NULL) {
                    *errorCode = 1; // 1 - ошибка баланса скобок
                }
                free(postfix);
                deleteStack(stack);
                return NULL;
            }
        }

        else if (isOperator(str[i])) {
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(str[i])) {
                postfix[k++] = pop(stack);
                postfix[k++] = ' ';
            }
            push(stack, str[i]);
        }

        i++;
    }

    while (!isEmpty(stack)) {
        char head = pop(stack);
        if (head == '(') {
            if (errorCode != NULL) {
                *errorCode = 1; // 1 - ошибка баланса скобок
            }
            free(postfix);
            deleteStack(stack);
            return NULL;
        }
        postfix[k++] = head;
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';

    deleteStack(stack);

    return postfix;
}