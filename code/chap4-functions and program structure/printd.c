#include <stdio.h>

void printd(int n);

/**
 * 功能： 把一个数字以char的形式一个个字符打印出来
 * 目标： 为了说明嵌套的用法
*/
int main(){
    printd(-123);
    printf("\n");
}

void printd(int n){
    if(n < 0){
        putchar('-');
        n = -n;
    }
    if(n / 10){
        printd(n / 10);
    }
    putchar( n % 10 + '0');
}
