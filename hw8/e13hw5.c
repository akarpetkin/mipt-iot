#include <stdio.h>
#include <stdbool.h>

const int ARRAY_SIZE = 10;

bool is_valid(int a) {
    return ((a / 10) % 10) == 0;
}

int fill_result(int *arr, int *result) {

    int i = 0;
    for (int j = 0; j < ARRAY_SIZE; j++) {
        if (is_valid(arr[j]) == true) {
            result[i] = arr[j];
            i++;
        }
    }

    return i;
}

int main(void) {   
    int arr[ARRAY_SIZE];  
    int result[ARRAY_SIZE]; 

    for (int i = 0; i < ARRAY_SIZE; i++) {
         scanf("%d", &arr[i]);
    };

    int size = fill_result(arr, result);
    if (size > 0) {
        for (int i = 0; i < size - 1; i++) {
            printf("%d ", result[i]);
        };

        printf("%d\n", result[size - 1]);
    }
    
    return 0;         
} 