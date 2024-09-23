#include <stdio.h>

int main(void) {  
    int number = 0;  
    scanf("%d", &number);

    int result = 0;
    while (number != 0) {
        result = result * 10 + number % 10;
        number /= 10;
    }

    printf("%d", result);

    return 0;         
} 