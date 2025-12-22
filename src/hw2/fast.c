#include <stdio.h>

int main()
{

    int x;
    scanf("%d", &x);

    int t = x * x;

    int res = ((t + x) * (t + 1) + 1);

    printf("%d", res);

    return 0;
}