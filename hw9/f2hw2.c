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

void print_array(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    printf("%d\n", arr[n - 1]);
}

void sort_even_odd(int n, int arr[]) {
    int even[n];
    int odd[n];
    int evenIdx = 0, oddIdx = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2==0) {
            even[evenIdx++] = arr[i];
        } else {
            odd[oddIdx++] = arr[i];
        }
    }

    for (int i = 0; i < evenIdx; i++) {
        arr[i] = even[i];
    }

    for (int i = 0; i < oddIdx; i++) {
        arr[evenIdx + i] = odd[i];
    }
}

int main(void) {   
    int arr[ARRAY_MAX_SIZE];
    int size = input_array(arr);
    
    sort_even_odd(size, arr);
    print_array(size, arr);

    return 0;         
} 