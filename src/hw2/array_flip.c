#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *x, int start, int end)
{
    while (start < end)
    {
        swap(&x[start], &x[end]);
        start++;
        end--;
    }
    
}

void swap_blocks(int *x, int m, int n)
{
    reverse(x, 0, m - 1);
    reverse(x, m, m + n - 1);
    reverse(x, 0, m + n -1);
}

int main(void)
{
    int m = 0, n = 0;

    printf("Введите длину первой части (m): ");
    scanf("%d", &m);
    printf("Введите длину второй части (n): ");
    scanf("%d", &n);

    int total_len = m + n;

    int *x = (int*)malloc(total_len * sizeof(int));

    if (x == NULL) {
        printf("Ошибка: Не удалось выделить память!\n");
        return 1;
    }

    printf("Введите %d чисел через пробел: ", total_len);
    for (int i = 0; i < total_len; i++) {
        scanf("%d", &x[i]);
    }

    printf("\nМассив ДО:    ");
    for (int i = 0; i < total_len; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    swap_blocks(x, m, n);

    printf("Массив ПОСЛЕ: ");
    for (int i = 0; i < total_len; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;

}