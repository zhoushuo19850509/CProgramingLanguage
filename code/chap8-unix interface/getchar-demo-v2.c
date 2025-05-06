#include <stdio.h>

int getchar(void);

/**
 * 功能：实现getchar()的功能，从标准输入读取字节
 * 目标： 为了说明read()函数在getchar中的作用
 * 备注： 本demo通过read()函数每次读取n个字节
 */
int main(){
    int nc;
    nc = 0;

    while( getchar() != EOF){
        nc++;
    }
    printf("print total char count : %d \n",nc);
}

#define BUFSIZE 1000


int getchar(void){

    static char buf[BUFSIZE];   // 保存
static char * bufp = buf;
static int n = 0;

    if(n == 0){
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    /**
     * 如果缓存中还有char，就从缓存中读取；
     * 然后通过移动指针，把缓存指向下一个char
     */
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
