#include <stdio.h>

void calc_avg(int a, int b, int c) {
    printf("%.2f\n", (a+b+c)/(float)3);
}

int main(void) { 
    int a=0, b=0, c=0;
    scanf("%d %d %d", &a, &b, &c);

    calc_avg(a, b, c);
    return 0;         
} 