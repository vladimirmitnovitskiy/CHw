#include "CircularList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    int m = 0;

    printf("Введите числов войнов n и шаг убийства m: ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("Введены некоректные значения\n");
        return 1;
    }

    CircularList* squad = initCircularList(n);
    int survivor = kill(squad, m);

    printf("Выживший на позиции %d\n", survivor);

    return 0;
}