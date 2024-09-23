#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

const int MIN_NUMER = 10;

bool check_lucky(int n) {
    int digitSum = 0;
    int digitsMult = 1;

    while (n != 0) {
         int digit = (n % 10);
         digitSum +=digit;
         digitsMult *= digit;

         n /= 10; 
    }

    return digitSum == digitsMult;
}

int main(void) {  
    setlocale(LC_ALL, "Rus");

    int number = 0;  
    scanf("%d", &number);
    if (number <= MIN_NUMER) {
        printf("Не корректные входные параметры. Число должно быть больше %d", MIN_NUMER);
        return 0;
    }

    int resultCount = 0;
    for (int i = MIN_NUMER; i <= number; ++i) {
        if (check_lucky(i)) {
            if (resultCount > 0) 
                printf(" ");

            printf("%d", i);
            resultCount++;
        }
    }

    return 0;         
} 