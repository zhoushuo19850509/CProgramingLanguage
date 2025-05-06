#include <stdio.h>

int getchar(void);

/**
 * 功能：实现getchar()的功能，从标准输入读取字节
 * 目标： 为了说明read()函数在getchar中的作用
 * 备注： 本demo通过read()函数每次读取一个字节
 */
int main(){
    int nc;
    nc = 0;

    while( getchar() != EOF){
        nc++;
    }
    printf("print total char count : %d \n",nc);
}

int getchar(void){
    char c;
    return (read(0, &c, 1)) == 1 ? (unsigned char) c: EOF;
}
