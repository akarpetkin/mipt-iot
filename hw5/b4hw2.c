#include <stdio.h>

const int DIGITS_NUMER = 3;

int main(void) {  
    int number = 0;  
    scanf("%d", &number);

    int digits = 0; 
    while (number != 0) {
         number /= 10; 
         digits++; 
    }

    printf(digits == DIGITS_NUMER ? "YES" : "NO");

    return 0;         
} 