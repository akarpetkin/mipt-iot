#include <stdio.h>

int max_digit(int a) {
    int current = a;
    int max = 0;
    
    while (current != 0) {
        int digit = (current % 10);
        current = current / 10;

        if (digit > max) {
            max = digit;
        }
    }

    return max;
}

int main(void) { 
    int a=0;
    scanf("%d", &a);

    printf("%d", max_digit(a));
    
    return 0;         
} 