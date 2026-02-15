#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    BRACKET_ROUND = 1,
    BRACKET_SQUARE = 2,
    BRACKET_CURLY = 3
} BracketType;


char* getString(int* len)
{
    *len = 0;
    int cap = 1;
    char* s = (char*)malloc(sizeof(char));

    char c = getchar();

    while (c != '\n') {
        s[(*len)++] = c;

        if (*len >= cap) {
            cap *= 2;
            s = (char*)realloc(s, cap * sizeof(char));
        }

        c = getchar();
    }

    s[*len] = '\0';

    return s;
}

bool bracketBalance(char* str)
{
    int len = strlen(str);
    Stack* brackets = initStack();

    bool isBalanced = true;

    for (int i = 0; i < len; i++) {
        switch (str[i]) {
        case '(':
            push(brackets, BRACKET_ROUND);
            break;
        case '[':
            push(brackets, BRACKET_SQUARE);
            break;
        case '{':
            push(brackets, BRACKET_CURLY);
            break;

        case ')':
            if (isEmpty(brackets)) {
                break;
            }
            if (pop(brackets) != BRACKET_ROUND) {
                isBalanced = false;
            }
            break;

        case ']':
            if (isEmpty(brackets)) {
                break;
            }
            if (pop(brackets) != BRACKET_SQUARE) {
                isBalanced = false;
            }
            break;

        case '}':
            if (isEmpty(brackets)) {
                break;
            }
            if (pop(brackets) != BRACKET_CURLY) {
                isBalanced = false;
            }
            break;

        default:
            break;
        }

        if(!isBalanced) {
            break;
        }
    }

    if (isBalanced) {
        isBalanced = isEmpty(brackets);
    }

    deleteStack(brackets);

    return isBalanced;
}

int main()
{
    int len = 0;

    printf("Введите строку: ");
    char* s = getString(&len);
    if (bracketBalance(s)) {
        printf("Баланс соблюдён\n");
    } else {
        printf("Баланс НЕ соблюдён\n");
    }

    free(s);

    return 0;
}