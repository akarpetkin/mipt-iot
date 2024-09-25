#include <stdio.h>
#include <inttypes.h>
#include <math.h>

uint64_t calc_grains(int n) {
    return (uint64_t) 1 << (n - 1);;
}

int main(void) {  
    int n = 0;
    scanf("%d", &n);

    if (n < 1 || n > 64) {
        printf("Не корректные входные параметры. Число должно быть в диапазоне от 1 до 64");
        return 0;
    }

    printf("%"PRIu64"\n", calc_grains(n));
  
    return 0;         
} 
