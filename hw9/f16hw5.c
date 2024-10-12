#include <stdio.h>

int is_black(char a, int b) {
    int sum = (66 - (int)a + b);
    if ( sum % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {   
    char a;
    int b;

    scanf("%c%d", &a, &b);
    printf("%s\n", is_black(a, b) ? "BLACK" : "WHITE ");

    return 0;      
} 