#include <stdio.h>

void strcatA(char s[], char t[]);
/**
 * 字符串拼接
*/
int main(){
    char target[10];
    char str[10];
    str[0] = '2';
    str[1] = '3';
    str[2] = '1';
    str[3] = '0';
    str[4] = '5';
    str[5] = '1';
    str[6] = '3';
    str[7] = '3';
    str[8] = '\0';

    strcatA(target, str);
    printf("concatenated string: %s \n", target);
}

/**
 * string concatenate 字符串拼接
 * 把char array t 拼接到char array s后面
*/
void strcatA(char s[], char t[]){
    int i,j;
    
    i= j = 0;

    while(s[i] != '\0'){
        i++;
    }
    while( (s[i++] = t[j++]) != '\0'){
        ;
    }
}

