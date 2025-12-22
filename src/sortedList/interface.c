#include "sortedList.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void assertListContent(SortedList* list, int* expectedValues, int count)
{
    Num* current = list->head;
    for (int i = 0; i < count; i++) {
        assert(current != NULL);
        assert(current->value == expectedValues[i]);
        current = current->next;
    }
    assert(current == NULL);
}

void runTests()
{
    printf("Running test...\n");
    // --- TEST 1: Initialization ---
    SortedList* list = initList();
    assert(list != NULL);
    assert(list->head == NULL);
    printf("[OK] Init test passed\n");

    // --- TEST 2: Insertion (Sorted Order) ---
    // 1. Insert into empty list
    assert(add(list, 20) == true);
    // Expect: 20
    assert(list->head->value == 20);

    // 2. Insert at beginning (smaller than current head)
    assert(add(list, 10) == true);
    // Expect: 10 -> 20
    assert(list->head->value == 10);
    assert(list->head->next->value == 20);

    // 3. Insert at end (larger than all)
    assert(add(list, 30) == true);
    // Expect: 10 -> 20 -> 30

    // 4. Insert in middle
    assert(add(list, 15) == true);
    // Expect: 10 -> 15 -> 20 -> 30

    // Check entire order
    int expectedOrder1[] = { 10, 15, 20, 30 };
    assertListContent(list, expectedOrder1, 4);
    printf("[OK] Insertion and sorting test passed\n");

    // --- TEST 3: Duplicates ---
    // Add a number that already exists
    assert(add(list, 20) == true);
    // Expect: 10 -> 15 -> 20 -> 20 -> 30
    int expectedOrder2[] = { 10, 15, 20, 20, 30 };
    assertListContent(list, expectedOrder2, 5);
    printf("[OK] Duplicates test passed\n");

    // --- TEST 4: Deletion ---
    // 1. Delete head
    assert(deleteByValue(list, 10) == true);
    // Expect: 15 -> 20 -> 20 -> 30
    assert(list->head->value == 15);

    // 2. Delete from middle
    assert(deleteByValue(list, 20) == true); // Removes first found 20
    // Expect: 15 -> 20 -> 30

    // 3. Delete tail
    assert(deleteByValue(list, 30) == true);
    // Expect: 15 -> 20
    int expectedOrder3[] = { 15, 20 };
    assertListContent(list, expectedOrder3, 2);

    // 4. Delete non-existent element
    assert(deleteByValue(list, 999) == false);
    // List should remain unchanged
    assertListContent(list, expectedOrder3, 2);

    printf("[OK] Deletion test passed\n");

    // --- Cleanup ---
    freeList(list);

    printf("All tests were passed successfully.\n");
}

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--test") == 0) {
            runTests();
            return 0;
        }
    }

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