#include <stdio.h>

void calc_sum(int a, int b, int c) {
    printf("%d+%d+%d=%d\n", a, b, c, (a+b+c));
}

void calc_mult(int a, int b, int c) {
    printf("%d*%d*%d=%d\n", a, b, c, (a*b*c));
}

int main(void) { 
    int a=0, b=0, c=0;
    scanf("%d %d %d", &a, &b, &c);

    calc_sum(a, b, c);
    calc_mult(a, b, c);
    return 0;         
} 