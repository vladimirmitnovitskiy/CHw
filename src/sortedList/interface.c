#include "sortedList.h"
#include <stdio.h>

int main(void)
{
    SortedList* sList = initList();
    int command = 0;

    while (1) {
        printf("\nВыберите действие: \n");
        printf("    0 - Выйти из программы\n");
        printf("    1 - добавить значение в сортированный список\n");
        printf("    2 - удалить значение из списка\n");
        printf("    3 - распечатать список\n");
        printf("->  ");
        scanf("%d", &command);
        int value = 0;
        switch (command) {
        case 0:
            freeList(sList);
            return 0;
        case 1:
            scanf("%d", &value);
            add(sList, value);
            break;
        case 2:
            scanf("%d", &value);
            deleteByValue(sList, value);
            break;
        case 3:
            printList(sList);
            break;
        default:
            printf("Неверная команада!\n");
            break;
        }
    }
}