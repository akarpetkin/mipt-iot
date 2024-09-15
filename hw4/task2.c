#include <stdio.h>

int max(int a, int b) {
    return a >= b ? a : b;
}

int main(void) {   
    int a=0, b=0, c=0;  

    scanf("%d %d %d", &a, &b, &c);
    printf("%d", max(a, max(b, c)));
   
    return 0;         
} 