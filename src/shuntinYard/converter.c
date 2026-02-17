#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#include <ctype.h>

#define MAX 100

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

char* infixToPostfix(const char* str)
{
    Stack* stack = initStack();

    int i = 0;
    int k = 0;
    char* postfix = malloc(MAX * sizeof(char));
    if (!postfix){
        return NULL;
    }

    while (str[i] != '\0'){
        if (isspace(str[i])){
            i++;
            continue;
        }

        if (isdigit(str[i])){
            postfix[k++] = str[i];
            postfix[k++] = ' ';
        }
        else if (str[i] == '('){
            push(stack, str[i]);
        }

        else if (str[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[k++] = pop(stack);
                postfix[k++] = ' ';
            }
            
            if (!isEmpty(stack)){
                pop(stack);
            }
            else{
                printf("Ошибка баланса скобок\n");
                return NULL;
            }
        }
        
        else if (isOperator(str[i])){
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(str[i])){
                postfix[k++] = pop(stack);
                postfix[k++] = ' ';
            }
            push(stack, str[i]);

        }

        i++;
    }

    while (!isEmpty(stack))
    {
        char head = pop(stack);
        if (head == '('){
            printf("Ошибка баланса скобок\n");
            return NULL;
        }
        postfix[k++] = head;
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';
    
    deleteStack(stack);
    
    return postfix;
}