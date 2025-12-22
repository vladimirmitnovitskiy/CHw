#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getString(int* len)
{
    *len = 0;
    int cap = 1;
    char* s = (char* ) malloc(sizeof(char));

    char c = getchar();

    while (c != '\n'){
        s[(*len)++] = c;

        if (*len >= cap) {
            cap *= 2;
            s = (char*) realloc(s, cap * sizeof(char));
        }

        c = getchar();
    }

    s[*len] = '\0';

    return s;    
}

bool balance(char* stream)
{
    long balance = 0;
    bool error_found = false;
    int len = strlen(stream);

    for (int i = 0; i<len; i++) {

        if (stream[i] == '\n' && stream[i] == EOF){
            break;
        }

        if (error_found) {
            continue;
        }

        if (stream[i] == '(') {
            balance++;
        } else if (stream[i] == ')') {
            balance--;
        }

        if (balance < 0) {
            error_found = true;
        }
    }

    return !error_found && (balance == 0);
}

int main()
{
    int len;

    printf("Введите строку: ");
    char *s = getString(&len);
    if (balance(s)) {
        printf("Баланс соблюдён\n");
    } else {
        printf("Баланс НЕ соблюдён\n");
    }

    free(s);

    return 0;
}