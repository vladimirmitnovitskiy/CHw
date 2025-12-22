#include "CircularList.h"
#include <stdio.h>
#include <stdlib.h>

int kill(CircularList* circle, int m)
{
    if (!circle->tail)
        return 0;
    if (m <= 0)
        return 0;

    Node* current = circle->tail;

    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            current = current->next;
        }

        Node* victim = current->next;
        current->next = victim->next;

        free(victim);
    }
    circle->tail = current;

    return current->id;
}

int main(void)
{
    int n = 0;
    int m = 0;

    printf("Введите числов войнов n и шаг убийства m: ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("Введены некоректные значения\n");
        return 1;
    }

    CircularList squad = initCircularList(n);
    int survivor = kill(&squad, m);

    printf("Выживший на позиции %d\n", survivor);
    free(squad.tail);

    return 0;
}