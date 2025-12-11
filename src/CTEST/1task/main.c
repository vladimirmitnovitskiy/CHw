#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

int compare(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    return int_a - int_b; 
    
}

int main(void)
{
    Array a;

    initArray(&a, 2);


    printf("Введите числа(0 - конец ввода): ");

    int inp = 1;

    while (inp != 0)
    {
        scanf("%d", &inp);
        insertArray(&a, inp);
    }

    qsort(a.array, a.used, sizeof(int), compare);
    removeZero(&a);

    printf("Результат:\n");
    
    for (size_t i = 0; i < a.used; i++) {
        
        int count = 1;
        
        while (i + 1 < a.used && a.array[i] == a.array[i+1]) {
            count++;
            i++; 
        }
        
        printf("%d - %d шт.\n", a.array[i], count);
    }
    
    freeArray(&a);
    return 0;
}