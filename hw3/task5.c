#include <stdio.h>

void calc_digit_mult(int a) {
    int current = a;
    int total = 1;
    
    while (current != 0) {
        total *= (current % 10);
        current = current / 10;
    }

    printf("%d", total);
}

int main(void) { 
    int a=0;
    scanf("%d", &a);

    calc_digit_mult(a);
    return 0;         
} 