#include <stdio.h>

unsigned short calc_count_of_bits(unsigned int a) {
    unsigned short sum = a % 2;

    if (a > 0) {
      sum += calc_count_of_bits(a / 2);
      
    }
    return sum;
}

int main(void) {   
    unsigned int a = 0;  

    scanf("%d", &a);
    printf("%d", calc_count_of_bits(a));
    
    return 0;         
} 