#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * 验证string.h提供的各种函数方法
 */
int main(){
    /**
     * 验证
     * 1.strcpy() 拷贝字符串
     * 2.strcat() 拼接字符串
     */
    char s[100];
    strcpy(s,"hello");
    char *t = "gogogo";
    strcat(s,t);
    printf("strcat() result: %s \n ", s);

    


}

