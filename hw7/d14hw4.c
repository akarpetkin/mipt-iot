#include <stdio.h>
#include <math.h>

const char delimiter = ' ';

void scan_number(unsigned short i) {
    int current = 0;
    scanf("%d", &current);

    if (current == 0) 
        return;

    if (abs(current) % 2 == 1) {
        if (i > 0) {
            printf("%c", delimiter);
        }

        printf("%d", current);
        i++;
    }

    scan_number(i);
}

int main(void) {  
    unsigned short i = 0; 
    scan_number(i);
  
    return 0;         
} 