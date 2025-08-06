#include <stdio.h>
#include <stdlib.h>

/**
 * 功能： 使用system()函数，执行某个本地脚本命令，比如date命令
 * 目标： 试用syslib.h中的system()函数
 */
int main(){
    printf("start system-demo ...\n");
    system("date");
}