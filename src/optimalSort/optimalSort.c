#include "sort.h"
#include <stdio.h>

int main(void)
{
    int arr[100] = {};
    int original[100] = {};

    int count = 0;
    char term = 0;

    while (count < 100 && scanf("%d%c", &arr[count], &term) == 2) {
        original[count] = arr[count];
        count++;
        if (term == '\n')
            break;
    }

    if (count == 0)
        return 0;

    quickSort(arr, 0, count - 1);

    int countNums = 0;

    for (int i = 0; i < count; i++) {
        if (arr[i] != original[i])
            countNums++;
    }

    return countNums;
}