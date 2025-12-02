#include <stdio.h>

int main(void)
{
    int ways[28] = { 0 };

    for (int d1 = 0; d1 <= 9; d1++) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                int sum = d1 + d2 + d3;
                ways[sum]++;
            }
        }
    }

    long long total_lucky_tickets = 0;

    for (int k = 0; k <= 27; k++) {
        long long combinations = ways[k];
        long long combinations_squared = combinations * combinations;

        total_lucky_tickets += combinations_squared;
    }

    printf("Общее число счастливых билетов: %lld\n", total_lucky_tickets);

    return 0;
}