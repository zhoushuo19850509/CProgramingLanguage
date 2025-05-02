#include "calc.h"
#include <stdio.h>
#include <ctype.h>

/*
 * 功能：不断读取下一个元素： 数字或者操作符
 * @param 如果getop()读取到的是一个数字，
          就以string(char array)的形式返回，放在这个param中
          比如读取到数字234，就返回"234\0",放在s[]中
 * @return 返回元素类型，如果是操作符，
          比如'+'/'-'/'*'/'/'，就返回这些操作符的ASCII码对应的数字
          如果是数字，就返回NUMBER
 */
 int getop(char s[]){
    int c;
    int i;

    // 略过空格
    while( (s[0] = (c = getch())) == ' ' || c == '\t'  ){
        ;
    }

    s[1] = '\0';
    // 读取到的字符是非数字，就立即返回，一般来说是'+'/'-'/'*'/'/'这些操作符
    if(!isdigit(c) && c != '.'){
        // printf("return non digit ... %c \n",c);
        return c;
    }
    i = 0;
    // 读取数字（整数部分）
    if(isdigit(c)){
        while( isdigit( s[++i] = (c = getch()) )){
            ;
        }
    }
    // 读取数字（小数部分）
    if(c == '.'){
        while( isdigit( s[++i] = (c = getch()) )){
            ;
        }
    }
    /**
        因为读取到的数字是以string的形式保存在s[]中，
        所以s[]要以'\0'结尾，这已经是惯例了
     */
    s[i] = '\0';
    // 对于多读取的那个字符，要退回去，避免影响下一轮循环
    if(c != EOF){
        ungetch(c);
    }
    // printf("return number: %s \n", s);
    return NUMBER;
}