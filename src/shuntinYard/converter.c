#include "converter.h"
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
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

void infixToPostfix(const char* expr)
{
    Stack stack;
    initializeStack(&stack);

    int i = 0;
    int len = (int)strlen(expr);

    while (i < len) {
        char c = expr[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (isdigit(c)) {
            // Читаем число целиком (включая дробную часть)
            while (i < len && (isdigit(expr[i]) || expr[i] == '.')) {
                printf("%c", expr[i]);
                i++;
            }
            printf(" ");
            continue;
        }

        if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(')
                printf("%c ", pop(&stack));
            
            // Удаляем открывающую скобку из стека
            if (!isEmpty(&stack) && peek(&stack) == '(')
                pop(&stack);
        } else if (isOperator(c)) {
            while (!isEmpty(&stack) && getPrecedence(peek(&stack)) >= getPrecedence(c))
                printf("%c ", pop(&stack));
            
            push(&stack, c);
        }

        i++;
    }

    // Выводим оставшиеся операторы
    while (!isEmpty(&stack))
        printf("%c ", pop(&stack));

    printf("\n");
    
    // Обязательная очистка памяти динамического стека
    destroyStack(&stack);
}