#include <stdio.h>

int calc_nod(int a, int b) {
  if (a % b == 0)
    return b;

  if (b % a == 0)
    return a;

  if (a > b)
    return calc_nod(a%b, b);

  return calc_nod(a, b%a);
}

int main(void) {  
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    
    printf("%d", calc_nod(a, b));
 
    return 0;         
} 
