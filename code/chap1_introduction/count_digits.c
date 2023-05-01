#include <stdio.h>

#define OUT 0
#define IN 1

/**
 * 统计各个数字出现的次数 这里为了说明array的用法
*/
int main(){
    int c, i, nwhite, nother;
    int digits[10];

    nwhite = nother = 0;
    for( i = 0; i < 10; i++){
        digits[i] = 0;
    }

    while( (c = getchar()) != EOF){

        // 如果碰到0-9的字符，就统计进去
        if(c >= '0' && c <= '9'){
            digits[c - '0']++;
        }
        
        /**
         * 如果读取到' '/'\n'/'\t'，
         * 就说明找到了word的分隔符
         * 重置一下状态： state = OUT
         */
        if(c == ' ' || c == '\n' || c == '\t'){
            nwhite++;
        }else {
            nother++;
        }
    }

    for( i = 0; i < 10; i++){
        printf("occurence of digit %d is : %d \n",
         i, digits[i]);        
    }
    printf("print whitespace count : %d \n",nwhite);
    printf("print other char count : %d \n",nother);
}