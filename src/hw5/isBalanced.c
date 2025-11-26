#include "funcs.h"

int isBalanced(const char *str)
{
    char stack[1000];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];

        // если открывающая скобка то кладём в стек
        if (c == '(' || c == '[' || c == '{')
        {
            stack[++top] = c;
        }
        // если закрывающая то проверяем
        else if (c == ')' || c == ']' || c == '}')
        {
            if (top == -1) return 0; // стэк пуст — ошибка

            char open = stack[top--]; // достаём верхний элемент

            if ((open == '(' && c != ')') ||
                (open == '[' && c != ']') ||
                (open == '{' && c != '}'))
            {
                return 0; // типы не совпали
            }
        }
    }

    return top == -1; // если стек пуст то всё ок
}
