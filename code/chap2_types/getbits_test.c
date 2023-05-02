#include <stdio.h>


unsigned getbits(unsigned x, int p, int n);

int main(){

    int n ;
    n = 0b11111111;
    printf("%d \n", n);

    int result;
    result = getbits(n,4,3);
    printf("%d \n", result);

}

/**
 * 从右往左，从第p个位置开始，获取n个bit的元素
 * 比如getbits(x,4,3)，就是获取4,3,2这三个位置的bit
*/
unsigned getbits(unsigned x, int p, int n){
    return x >> (( p + 1 - n)) & ~(~0 << n);
}
