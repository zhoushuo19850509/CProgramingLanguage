#include <stdio.h>
#include <string.h>

int trim(char s[]);

/**
 * 功能：提供trim()函数
 * 作用：用来说明break的用法
 * 要点: char[]表示string，要以'\0'结尾
 */
int main(){
    // "hello..   \0";
    char s[11];
    s[0] = 'h';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = '.';
    s[6] = '.';
    s[7] = ' ';
    s[8] = ' ';
    s[9] = ' ';
    s[10] = '\0';

    printf("before trim : %s\n ",s);
    int len = strlen(s);
    printf("before trim length: %d\n ",len);

    int n = trim(s);
    printf("n:  %d \n", n);
    printf("after trim %s \n", s);
    len = strlen(s);
    printf("after trim length: %d\n ",len);
}

int trim(char s[]){

    int n;
    // 从右往左遍历
    for(n = strlen(s) -1 ; n >= 0 ;n--){
        printf("loop of n: %d \n", n);
        // 一旦碰到一个不为' '的字符，就跳出整个for循环(当然\n\t除外)
        if( s[n] != ' ' && s[n] != '\n' && s[n] != '\t'){
            break;
        }
    }
    s[n+1] = '\0';
    return n;
}
