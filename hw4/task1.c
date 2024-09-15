#include <stdio.h>

int main(void) {   
    int a=0, b=0;  

    scanf("%d %d", &a, &b);

    if (a >= b) {
        printf("%d %d", b, a);
    } else {
        printf("%d %d", a, b);
    }
    
    return 0;         
} 