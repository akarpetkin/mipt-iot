#include <stdio.h>

const int ARRAY_SIZE = 5;

float calc_average(int *arr) {
 
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
         sum +=arr[i];
    }
    
    return (float)sum / ARRAY_SIZE;
}

int main(void) {   
    int arr[ARRAY_SIZE];  

    for (int i = 0; i < ARRAY_SIZE; i++) {
         scanf("%d", &arr[i]);
    }
    
    printf("%.3f\n", calc_average(arr));
    
    return 0;         
} 