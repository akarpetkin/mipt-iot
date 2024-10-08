#include <stdio.h>

int main(void) {   
    int n[5];  

    scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);

    int max = n[0];
    int min = max;

    for (int i = 1; i < 5; ++i) {
        if (n[i] > max) {
            max = n[i];
        }

        if (n[i] < min) {
            min = n[i];
        }
    }

    printf("%d", max + min);
    
    return 0;         
} 