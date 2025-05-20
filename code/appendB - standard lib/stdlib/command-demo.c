#include <stdio.h>
#include <stdlib.h>

/**
 * 功能：通过C语言执行shell脚本
 * 目标：介绍如何通过stdlib.h提供的库函数： sytem() 执行shell脚本
*/
int main(){
    printf("start sytem execute ... \n");
    system("date");
    printf("finish sytem execute ... \n");
}