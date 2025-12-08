#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    printf("Введите a и b: ");
    scanf("%d %d", &a, &b);

    int c = 0;
    int sign = 1;

    // проверяем знаки и меняем если они отрицаетльные
    if (a < 0) {
        a = -a;
        sign = -sign;
    }
    if (b < 0) {
        b = -b;
        sign = -sign;
    }

    // вычитаем b из a пока можем
    while (a >= b) {
        a = a - b;
        c++;
    }

    c = c * sign; // возвращаем знак

    printf("Неполное частное: %d\n", c);
    return 0;
}