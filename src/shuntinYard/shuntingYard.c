#include "converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[200] = {};
    int error = 0;

    printf("Введите выражение (не больше 200 символов): ");
    if (!fgets(str, sizeof(str), stdin))
        return 1;

    str[strcspn(str, "\n")] = 0;

    char* postfix = infixToPostfix(str, &error);

    if (error == 1) {
        printf("Ошибка: Нарушен баланс скобок!\n");
    } else if (error == 2) {
        printf("Ошибка: Ошибка выделения памяти!\n");
    } else if (postfix != NULL) {
        printf("Постфиксная форма: %s\n", postfix);
        free(postfix);
    }
    return 0;
}