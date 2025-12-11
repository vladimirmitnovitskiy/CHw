#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

// Тесты
// Функция проверяет, совпадает ли список с ожидаемым массивом чисел
bool checkListContent(Node* head, int* expectedArr, int size)
{
    Node* temp = head;
    for (int i = 0; i < size; i++) {
        if (temp == NULL)
            return false;
        if (temp->value != expectedArr[i])
            return false;
        temp = temp->next;
    }
    if (temp != NULL)
        return false;
    return true;
}

void runTests()
{
    printf("Запуск тестов...\n");

    // ТЕСТ 1: Обычный список 1 -> 2 -> 3
    Node* list1 = NULL;
    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 3);

    // Разворачиваем
    list1 = reverseList(list1);

    // Ожидаем: 3 -> 2 -> 1
    int expected1[] = { 3, 2, 1 };
    assert(checkListContent(list1, expected1, 3) == true);
    freeList(list1);
    printf("[OK] Тест 1: 1->2->3 превратился в 3->2->1\n");

    // ТЕСТ 2: Список из одного элемента
    Node* list2 = NULL;
    append(&list2, 100);

    list2 = reverseList(list2);

    // Ожидаем: 100
    int expected2[] = { 100 };
    assert(checkListContent(list2, expected2, 1) == true);
    freeList(list2);
    printf("[OK] Тест 2: Одиночный элемент обработан корректно\n");

    // ТЕСТ 3: Пустой список
    Node* list3 = NULL;

    list3 = reverseList(list3);

    assert(list3 == NULL);
    printf("[OK] Тест 3: Пустой список остался пустым\n");

    // ТЕСТ 4: Длинный список
    Node* list4 = NULL;
    for (int i = 0; i < 5; i++)
        append(&list4, i); // 0->1->2->3->4

    list4 = reverseList(list4);

    int expected4[] = { 4, 3, 2, 1, 0 };
    assert(checkListContent(list4, expected4, 5) == true);
    freeList(list4);
    printf("[OK] Тест 4: Длинный список перевернут\n");

    printf("Все тесты пройдены!\n");
}

int main(void)
{
    runTests();
    return 0;
}