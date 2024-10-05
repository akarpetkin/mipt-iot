#include <stdio.h>
#include <math.h>

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void qsort_desc(int *arr, int size) {
    int i = 0;
    int j = size - 1;
    int mid = arr[size / 2];

    do {
        while(arr[i] < mid) {
            i++;
        }

        while(arr[j] > mid) {
            j--;
        }

        if (i <= j) {
            swap(&arr[i], &arr[j]);

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsort_desc(&arr[0], j + 1);
    }

    if (i < size) {
        qsort_desc(&arr[i], size - i);
    }
}

int main(void) {   
    int n = 0;  
    scanf("%d", &n);

    n = abs(n);
    if (n == 0) {
         printf("%d\n", n);
         return 0;
    }

    int size = 1;
    int k = n;
    while (k /= 10) size++;

    int result[size];

    int i = 0;
    while (n > 0) {
        result[i] = n % 10;
        n /= 10;
        i++;
    }

    qsort_desc(result, size);

    int number = 0;
    for (int i = 0; i < size; i++) {
         number += result[i] * pow(10, i);
    };

    printf("%d\n", number);
    
    return 0;         
} 