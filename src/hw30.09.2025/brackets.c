#include <stdio.h>
#include <string.h>

int main(void){
    //вводим строку
    char str[100];
    scanf("%s",str);

    //инициализируем перменные для подсчёта скобок
    int countL; // ")"
    int countR; // "("

    bool t = true;

    
    //считаем

    for (int i = 0; i<strlen(str); i++) {
        if (str[0] == ')'){
            t = false;
            break;
        }
        if (str[i] == ')'){
            countL++;
        }
        if (str[i] == '('){
            countR++;
        }
    }
    
    if (countL == countR && t != false){
        printf("Баланс\n");
    }
    else {
        printf("не баланс\n");
    }



    return 0;
}