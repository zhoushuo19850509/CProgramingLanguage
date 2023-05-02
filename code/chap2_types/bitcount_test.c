#include <stdio.h>


unsigned bitcount(unsigned x);

int main(){

    int n ;
    n = 0b11111111;
    printf("%d \n", n);

    int result;
    result = bitcount(n);
    printf("%d \n", result);

}

/**
 * 统计某个数字，以二进制的形式，出现1的次数
*/
unsigned bitcount(unsigned x){
    int count;
    for(count = 0; x != 0 ; x >>= 1){
        if(x & 01){
            count++;
        }
    }
    return count;
}
