#include "calc.h"
#include <stdio.h>

// 下面开始定义一个stack的数据结构
#define MAXVAL 100  // stack最多存放的元素数量

int sp = 0;  // stack下一个元素的位置
double val[MAXVAL];  // stack元素都放在这个array中

void push(double f){
    if(sp < MAXVAL){
        val[sp++] = f;
    }else{
        printf("error ! stack is full! ");
    }
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    }else{
        printf("error! stack is empty!");
        return 0.0;
    }
}