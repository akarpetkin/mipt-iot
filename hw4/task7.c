#include <stdio.h>

int max_array_value(int n[], int size) {
    int max = n[0];

    for (int i = 1; i < size; ++i) {
        if (n[i] > max) {
            max = n[i];
        }
    }

    return max;
}

int main(void) {   
    int n[5];  

    scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);
    printf("%d", max_array_value(n, 5));
   
    return 0;         
} 