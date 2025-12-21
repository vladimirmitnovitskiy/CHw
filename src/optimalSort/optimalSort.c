#include "sort.h"
#include <stdio.h>

int main(void)
{
    int arr[100];
    int original[100];

    int count = 0;
    char term;

    while (count < 100 && scanf("%d%c", &arr[count], &term) == 2) {
        original[count] = arr[count];
        count++;
        if (term == '\n')
            break;
    }

    if (count == 0)
        return 0;

    quick_sort(arr, 0, count - 1);

    int count_nums = 0;

    for (int i = 0; i < count; i++) {
        if (arr[i] != original[i])
            count_nums++;
    }

    return count_nums;
}