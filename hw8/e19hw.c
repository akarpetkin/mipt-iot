#include <stdio.h>
#include <math.h>

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

    for (int i = size - 1; i > 0; i--) {
         printf("%d ", result[i]);
    };

    printf("%d\n", result[0]);
    
    return 0;         
} 