#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* x, int start, int end)
{
    while (start < end) {
        swap(&x[start], &x[end]);
        start++;
        end--;
    }
}

void swapBlocks(int* x, int m, int n)
{
    reverse(x, 0, m - 1);
    reverse(x, m, m + n - 1);
    reverse(x, 0, m + n - 1);
}

int main(void)
{
    int m = 0, n = 0;

    printf("Введите длину первой части (m): ");
    scanf("%d", &m);
    printf("Введите длину второй части (n): ");
    scanf("%d", &n);

    int totalLen = m + n;

    int* x = (int*)malloc(totalLen * sizeof(int));

    if (x == NULL) {
        printf("Ошибка: Не удалось выделить память!\n");
        return 1;
    }

    printf("Введите %d чисел через пробел: ", totalLen);
    for (int i = 0; i < totalLen; i++) {
        scanf("%d", &x[i]);
    }

    printf("\nМассив ДО:    ");
    for (int i = 0; i < totalLen; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    swapBlocks(x, m, n);

    printf("Массив ПОСЛЕ: ");
    for (int i = 0; i < totalLen; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;
}