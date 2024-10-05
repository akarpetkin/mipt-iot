#include <stdio.h>

const int ARRAY_SIZE = 10;

int last_digit(int n) {
    return n % 10;
}

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void qsort_by_last_digit(int *arr, int size) {
    int i = 0;
    int j = size - 1;
    int mid = arr[size / 2];

    do {
        while(last_digit(arr[i]) < last_digit(mid)) {
            i++;
        }

        while(last_digit(arr[j]) > last_digit(mid)) {
            j--;
        }

        if (i <= j) {
            swap(&arr[i], &arr[j]);

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsort_by_last_digit(&arr[0], j + 1);
    }

    if (i < size) {
        qsort_by_last_digit(&arr[i], size - i);
    }
}

int main(void) {   
    int arr[ARRAY_SIZE];  

    for (int i = 0; i < ARRAY_SIZE; i++) {
         scanf("%d", &arr[i]);
    }
    
    qsort_by_last_digit(arr, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
         printf("%d ", arr[i]);
    };

    printf("%d\n", arr[ARRAY_SIZE - 1]);
    
    return 0;         
} 