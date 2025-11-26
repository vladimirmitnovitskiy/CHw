#include <stdio.h>
#include "funcs.h"

int main()
{
    char str[1000];

    printf("Введите строку со скобками: ");
    scanf("%999s", str);

    if (isBalanced(str))
    {
        printf("Скобки сбалансированы\n");
    }
    else
    {
        printf("Скобки несбалансированы\n");
    }

    return 0;
}
