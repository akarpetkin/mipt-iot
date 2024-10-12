#include <stdio.h>

const int SIZE = 5;

float calc_avg(int arr[][SIZE]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i][i];
    }

    return sum / SIZE;
}

int print_result(float avg, int arr[][SIZE]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] > 0 && arr[i][j] > avg) {
                count++;
            }
        }
    }

    return count;
}

int input_array(int arr[]) {
    int i = 0;
    do {
        int num;
        if (scanf("%d", &num) == 1) {
            arr[i++] = num;
        }

    } while (getchar() != '\n' && i < SIZE);
    arr[i];

    return i;
}

int main(void) {   
    int arr[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        input_array(arr[i]);
    }

    printf("%d\n", print_result(calc_avg(arr), arr));

    return 0;      
} 