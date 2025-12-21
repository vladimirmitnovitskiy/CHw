#include "bin.h"
#include <stdio.h>

void print_binary(int num)
{
    for (int i = 31; i >= 0; i--) {
        // Сдвигаем число вправо на i и берем последний бит (& 1)
        int bit = (num >> i) & 1;
        printf("%d", bit);

        // Добавляем пробелы для удобства чтения
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
}
