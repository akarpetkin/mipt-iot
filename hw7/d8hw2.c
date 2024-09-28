#include <stdio.h>

const char delimiter = ' ';

void print_num(int a, 
            int b) {

    if (a != b) { 
        printf("%d%c", a, delimiter);

        print_num(a < b ? (a + 1) : (a - 1), b);
    } else {
        printf("%d", b);
    }
}

int main(void) {   
    int a, b = 0;  

    scanf("%d %d", &a, &b);
    print_num(a, b);
    
    return 0;         
} 