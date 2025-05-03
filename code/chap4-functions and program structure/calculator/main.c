
#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100

/**
 * 功能： 实现一个计算器
 * 目标： 1.为了说明external variables的用法
 *       2.为了说明Header files的用法
 */
int main(){
    int type; 
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0){
                    push(pop() / op2);
                }else{
                    printf("error! zero divisor!");
                }                
                break;
            case '\n':
                printf("\t %.8g \n", pop());
                break;
            default:
                printf("unknow command! %s \n", s);
                break;
        }
    }
}
