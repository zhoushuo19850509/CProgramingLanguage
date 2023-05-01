#include <stdio.h>

int power(int base, int n);

/**
 * 这个代码主要是为了说明C function的用法
*/
int main(){
    int base = 2;
    int n = 10;
    int result = power(base, n);
    printf("base: %d power: %d result: %d \n", 
        base, n, result);
}

int power(int base, int n){
    int result = 1;
    int i;

    for(i = 1; i <= n; i++){
        result = result * base;
    }
    return result;
}
