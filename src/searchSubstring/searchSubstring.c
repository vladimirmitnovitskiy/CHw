#include <stdio.h>
#include <string.h>

int countOcc(char *s, char *s1)
{
    int count = 0;
    while ((s = strstr(s, s1)) != NULL) {
        count++;
        s++;
    }
    return count;
}


int main(void)
{

    char s[1000] = {};
    char s1[1000] = {};
    int count = 0;

    // принимаем строки
    printf("S: ");
    fgets(s, sizeof(s), stdin);
    printf("S1: ");
    fgets(s1, sizeof(s1), stdin);

    // убираем \n
    s[strcspn(s, "\n")] = '\0';
    s1[strcspn(s1, "\n")] = '\0';

    count = countOcc(s, s1);

    printf("Количество вхождений: %d\n", count);

    return 0;
}