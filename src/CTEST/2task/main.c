#include "permutation.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Тесты
void runTests()
{
    printf("Запуск тестов...\n");

    // Тест 1: Обычный случай
    // 315 -> 1,3,5 -> 135
    assert(getSmallestPermutation(315) == 135);
    printf("[OK] Test 1 passed (315 -> 135)\n");

    // Тест 2: Обратный порядок
    // 852 -> 2,5,8 -> 258
    assert(getSmallestPermutation(852) == 258);
    printf("[OK] Test 2 passed (852 -> 258)\n");

    // Тест 3: Число с нулем внутри
    // 502 -> 0,2,5 -> меняем 0 и 2 -> 205
    assert(getSmallestPermutation(502) == 205);
    printf("[OK] Test 3 passed (502 -> 205)\n");

    // Тест 4: Число с несколькими нулями
    // 5002 -> 0,0,2,5 -> меняем первый 0 и 2 -> 2005
    assert(getSmallestPermutation(5002) == 2005);
    printf("[OK] Test 4 passed (5002 -> 2005)\n");

    // Тест 5: Одна цифра
    assert(getSmallestPermutation(7) == 7);
    printf("[OK] Test 5 passed (7 -> 7)\n");

    // Тест 6: Уже отсортированное число
    assert(getSmallestPermutation(123) == 123);
    printf("[OK] Test 6 passed (123 -> 123)\n");

    // Тест 7: Большое число
    // 987654321 -> 123456789
    assert(getSmallestPermutation(987654321) == 123456789);
    printf("[OK] Test 7 passed (987654321 -> 123456789)\n");

    printf("Все тесты успешно пройдены!\n\n");
}

int main()
{
    runTests();

    long long n;
    printf("Введите натуральное число: ");
    if (scanf("%lld", &n) == 1) {
        if (n < 0) {
            printf("Ошибка: число должно быть натуральным (>0).\n");
        } else {
            long long res = getSmallestPermutation(n);
            printf("%lld\n", res);
        }
    } else {
        printf("Ошибка ввода.\n");
    }

    return 0;
}