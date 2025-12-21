#include <stdbool.h>
#include <stdio.h>

bool balance(FILE* stream)
{
    int c = 0;
    long balance = 0;
    bool error_found = false;

    while ((c = fgetc(stream)) != '\n' && c != EOF) {

        if (error_found) {
            continue;
        }

        if (c == '(') {
            balance++;
        } else if (c == ')') {
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
    printf("Введите строку: ");

    if (balance(stdin)) {
        printf("Баланс соблюдён\n");
    } else {
        printf("Баланс НЕ соблюдён\n");
    }

    return 0;
}