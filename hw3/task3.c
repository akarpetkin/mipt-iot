#include <stdio.h>

void calc_diff(int a, int b) {
    printf("%d\n", (a-b));
}

int main(void) { 
    int a=0, b=0;
    scanf("%d %d", &a, &b);

    calc_diff(a, b);
    return 0;         
} 