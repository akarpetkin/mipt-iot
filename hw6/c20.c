#include <stdio.h>
#include <stdbool.h>

bool check(char *str) {
    char stack[1000];
    int stackIdx = -1;

    int i = 0;
    while(str[i] != '.') {
        if (str[i] == '(') {
            stack[++stackIdx] = str[i];
        }

        if (str[i] == ')') {
            if (stackIdx < 0)
                return false;
                
            if (stack[stackIdx] == '(') {
                stackIdx--;
            } else {
                return false;
            }
        }

        i++;
    }

    return stackIdx < 0 ? true : false;
}

int main(void) {  
    char str[1000];
   
    scanf("%s", &str);
    printf(check(str) ? "YES" : "NO");
 
    return 0;         
} 