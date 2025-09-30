#include <stdio.h>

int main(void) {

    int n;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    //считаем нули
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count++;
        }
    }
    printf("Количество нулевых эллементов: %d\n", count);

    return 0; 
}