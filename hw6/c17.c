#include <stdio.h>
#include <stdbool.h>

bool is_happy_number(int n) {
    int digitSum = 0;
    int digitsMult = 1;

    while (n != 0) {
         int digit = (n % 10);
         digitSum +=digit;
         digitsMult *= digit;

         n /= 10; 
    }

    return digitSum == digitsMult;
}

int main(void) {  
    int a = 0;
    scanf("%d", &a);
    
    printf(is_happy_number(a) ? "YES" : "NO");
 
    return 0;         
} 