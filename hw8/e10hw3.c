#include <stdio.h>

const int ARRAY_SIZE = 12;
const int SHIFT_SIZE = 4;

void right_shift(int *arr, int n) {
    
    int i = 0;
    while (i < n) {
        int last = arr[ARRAY_SIZE - 1];
        for (int j = ARRAY_SIZE - 2; j >= 0; j--) {
            arr[j+1] = arr[j];
        }
        arr[0] = last;
        
        i++;
    }
}

int main(void) {   
    int arr[ARRAY_SIZE];  

    for (int i = 0; i < ARRAY_SIZE; i++) {
         scanf("%d", &arr[i]);
    }
    
    right_shift(arr, SHIFT_SIZE);

    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
         printf("%d ", arr[i]);
    };

    printf("%d\n", arr[ARRAY_SIZE - 1]);
    
    return 0;         
} 