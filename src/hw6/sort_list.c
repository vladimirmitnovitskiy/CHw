#include <stdio.h>
#include "list.h"

int main() {
    Node *head = NULL;
    int command, value;

    printf("Программа управления отсортированным списком.\n");

    while (1) {
        printf("\nВыберите действие:\n");
        printf("0 - выйти\n");
        printf("1 - добавить значение\n");
        printf("2 - удалить значение\n");
        printf("3 - распечатать список\n");
        printf("> ");
        scanf("%d", &command);

        switch (command) {
            case 0:
                freeList(head);
                printf("Выход...\n");
                return 0;
            case 1:
                printf("Введите значение для добавления: ");
                scanf("%d", &value);
                add(&head, value);
                break;
            case 2:
                printf("Введите значение для удаления: ");
                scanf("%d", &value);
                deleteValue(&head, value);
                break;
            case 3:
                printList(head);
                break;
            default:
                printf("Неверная команда. Попробуйте снова.\n");
        }
    }
}
