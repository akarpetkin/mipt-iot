#include <stdio.h>
#include <stdbool.h>

int main(void) {  
    int number = 0;  
    scanf("%d", &number);

    bool stopFlag = false;
    while (number != 0 && !stopFlag) {
         int digit = (number % 10);
         if (digit % 2 != 0)
            stopFlag = true;

         number /= 10; 
    }

    printf(stopFlag ? "NO" : "YES");

    return 0;         
} 