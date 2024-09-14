#include <stdio.h>

void calc_sum() {
    int a=0, b=0, c=0;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d+%d+%d=%d", a, b, c, (a+b+c));
}

int main(void) {                                  
    calc_sum();
    return 0;         
} 