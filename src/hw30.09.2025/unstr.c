#include <stdio.h>
#include <string.h>

int main(void){

    char s[1000], s1[1000];
    int count = 0;

    //принимаем строки
    printf("S: ");
    fgets(s, sizeof(s), stdin);
    printf("S1: ");
    fgets(s1, sizeof(s1), stdin);

    //убираем \n
    s[strcspn(s, "\n")] = '\0';
    s1[strcspn(s1, "\n")] = '\0';

    //ищем вхождения
    char *pos = s;
    while ((pos = strstr(pos, s1)) != NULL) {
        count++;
        pos++;
    }

    printf("Количество вхождений: %d\n", count);



    return 0;
}