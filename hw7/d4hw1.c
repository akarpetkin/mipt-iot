#include <stdio.h>

const char delimiter = ' ';

void print_num(unsigned int num, 
               unsigned short i) {

    if (num == 0 && i == 0) {
      printf("%d", num);  
      return;
    }            

    if (num > 0) { 
        print_num(num / 10, (i + 1));

        printf("%d", num % 10);
        if (i > 0)
            printf("%c", delimiter);
    } 
}

int main(void) {   
    unsigned int n = 0;  
    unsigned short i = 0; 

    scanf("%d", &n);
    print_num(n, i);
    
    return 0;         
} 