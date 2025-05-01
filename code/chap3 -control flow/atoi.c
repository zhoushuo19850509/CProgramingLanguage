#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

/**
 * 功能： 提供atoi()函数，将string 转化为int
 * 目标： 为了说明for的用法
 */
int main(){
    char *a = "  -229";
    // "  -123\0";
    char s[7];
    s[0] = ' ';
    s[1] = ' ';
    s[2] = '-';
    s[3] = '1';
    s[4] = '2';
    s[5] = '3';
    s[6] = '\0';
    int n = atoi(s);
    printf("result: %d \n", n);

    int n2 = atoi(a);
    printf("result: %d \n", n2);
}

//convert string to int
int atoi(char s[]){

    // skip spaces
    int i;
    for(i = 0; isspace(s[i]);i++){
        ;
    }
    printf("current i: %d \n ", i);

    // deal with sign
    int sign;
    if(s[i] == '-'){
        sign = -1;
    }else{
        sign = 1;
    }

    if(s[i] == '+' || s[i] == '-'){
        i++;
    }
    printf("sign: %d \n", sign);

    int result;
    for(result = 0; isdigit(s[i]); i++){
        result = 10 * result + (s[i] - '0');
    }
    
    return sign * result;

}