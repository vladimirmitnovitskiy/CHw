#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    for (int i = 0; i < len; i++) {
        switch (str[i]) {
        case '(':
            push(brackets, 1);
            break;
        case '[':
            push(brackets, 2);
            break;
        case '{':
            push(brackets, 3);
            break;

        case ')':
            if (pop(brackets) != 1) {
                deleteStack(brackets);
                return false;
            }
            break;

        case ']':
            if (pop(brackets) != 2) {
                deleteStack(brackets);
                return false;
            }
            break;

        case '}':
            if (pop(brackets) != 3) {
                deleteStack(brackets);
                return false;
            }
            break;

        default:
            break;
        }
    }

    bool result = isEmpty(brackets);
    deleteStack(brackets);

    return result;
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