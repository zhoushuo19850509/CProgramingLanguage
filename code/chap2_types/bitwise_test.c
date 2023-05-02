#include <stdio.h>


int strlenA(char a[]);

/**
 * MASK 其中0177是八进制(是数字0，不是字母O)，转换为10进制为127 : 
 * 转换为二进制为127
 * 如果用于& mask的话，那就是后7位保留，前面全部置为0
*/
#define MASK 0177

int main(){

    int a = 4;
    a = a << 2;  // 左移两位
    printf("%d \n", a);    

    // & 
    int n ;
    n = 0b11111111;
    n = n & MASK;  // 经过mask之后，只保留后7位，那么n变为0b01111111 等于127
    printf("MASK: %d \n", MASK);
    printf("%d \n",n);

}


