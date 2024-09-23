#include <stdio.h>
#include <locale.h>
#include <inttypes.h>

int main(void) {  
    setlocale(LC_ALL, "Rus");

    int a=0, b=0;  

    scanf("%d %d", &a, &b);
    if (b < a) {
        printf("Не корректные входные параметры. Число 1 должно быть меньше либо равно числа 2");
        return 0;
    }

    int curValue = a;
    int32_t sum = 0;
    while (curValue <= b) {
        sum += curValue * curValue;
        curValue++;
    }
    
    printf("%"PRIu32"\n", sum);

    return 0;         
} 