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

    long long totalLuckyTickets = 0;

    for (int k = 0; k <= 27; k++) {
        long long combinations = ways[k];
        long long combinationsSquared = combinations * combinations;

        totalLuckyTickets += combinationsSquared;
    }

    printf("Общее число счастливых билетов: %lld\n", totalLuckyTickets);

    return 0;
}