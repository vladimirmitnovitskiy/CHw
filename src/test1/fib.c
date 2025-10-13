//чётные числа фибо меньше 1_000_000


#include <stdio.h>




int main(void)
{
    int a = 0;
    int b = 1;
    int c = b;
    int sum = 0;

    while (b <= 1000000)
    {
        if (b % 2 == 0)
        {
            sum = sum + b;
        }


        b = a + b;
        a = c;
        c = b;

    }
    
    printf("%d \n", sum);



    return 0;
}

