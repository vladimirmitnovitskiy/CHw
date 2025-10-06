#include "algsort.h"

#include <stdio.h>

int main(void){
    //вводим
    int nums[100];
    int n = 0;
    int x;
    char c;

    while (n < 100 && scanf("%d", &x) == 1) {
        nums[n++] = x;
        c = getchar();
        if (c == '\n' || c == 'E0F') break;
        ungetc(c, stdin);
    }

    //сортируем
    int count = bsort(nums, n);

    //выводим

    for (int i=0; i < n; i++) {
        if (i>0) printf(" ");
        printf("%d", nums[i]);
    }
    printf("\n");

    return count;
}