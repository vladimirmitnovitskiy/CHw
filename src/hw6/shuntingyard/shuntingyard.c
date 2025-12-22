#include <stdio.h>
#include "converter.h"

int main()
{
    char expr[200];

    printf("Введите выражение: ");
    fgets(expr, sizeof(expr), stdin);

    printf("Постфиксная форма: ");
    infixToPostfix(expr);

    return 0;
}
