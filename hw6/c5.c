#include <stdio.h>

int calc_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    
    return sum;
}

int main(void) {  
    int a = 0;
    scanf("%d", &a);
  
    printf("%d\n", calc_sum(a));
 
    return 0;         
} 