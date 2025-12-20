#include "permutation.h"
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    return int_a - int_b;
}

long long getSmallestPermutation(long long n)
{
    if (n >= 0 && n <= 9)
        return n;

    int digits[25];
    int count = 0;

    long long temp = n;
    while (temp > 0) {
        digits[count++] = temp % 10;
        temp /= 10;
    }

    qsort(digits, count, sizeof(int), compare);

    if (digits[0] == 0) {
        for (int i = 1; i < count; i++) {
            if (digits[i] != 0) {
                int swapTemp = digits[0];
                digits[0] = digits[i];
                digits[i] = swapTemp;
                break;
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < count; i++) {
        result = result * 10 + digits[i];
    }

    return result;
}
