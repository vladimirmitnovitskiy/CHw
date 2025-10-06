#pragma once

//алгоритм сортировки пузырьком

int bsort(int arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        int countChange = 0; //количество обменов
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                countChange= 1;
            }
        }
        if (countChange == 0){
            break;
        }
        return countChange;
        
    }
}