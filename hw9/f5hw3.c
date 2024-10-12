#include <stdio.h>

const int ARRAY_MAX_SIZE = 100;

int input_array(int arr[]) {
    int i = 0;
    do {
        int num;
        if (scanf("%d", &num) == 1) {
            arr[i++] = num;
        }

    } while (getchar() != '\n' && i < ARRAY_MAX_SIZE);
    arr[i];

    return i;
}

int find_max_array(int size, int arr[]) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main(void) {   
    int arr[ARRAY_MAX_SIZE];
    int size = input_array(arr);
    
    printf("%d\n", find_max_array(size, arr));

    return 0;         
} 