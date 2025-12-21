#include "bin.h"
#include <stdio.h>

int main(void)
{
    int num1;
    int num2;
    int sum;

    printf("Введите два целых числа: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    sum = num1 + num2;

    printf("\nСложение в столбик\n\n");

    printf("  ");
    print_binary(num1);
    printf("  (%d)\n", num1);

    printf("+ ");
    print_binary(num2);
    printf("  (%d)\n", num2);

    printf("  ");
    for (int i = 0; i < 39; i++)
        printf("-");
    printf("\n");

    printf("  ");
    print_binary(sum);
    printf("  (BIN)\n");

    printf("\nСумма в десятичном виде: %d\n", sum);

    return 0;
}