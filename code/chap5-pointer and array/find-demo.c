#include <stdio.h>
#include <string.h>

int getlineA(char s[], int lim);
#define MAXLINE 1000

/**
 * 功能： 模拟find命令： find aaa xxx
      备注： 功能和chap4/finds-matching.c 功能类似，
            就是打印、统计匹配关键字的行
 * 目标： 为了说明main argument的用法
 */
int main(int argc, char *argv[]){

    char line[MAXLINE];
    int found = 0;
    // 判断命令的用法是否合法
    if(argc != 2){
        printf("Usage: finds pattern \n");
    }else{
        // 不断读取标准输入内容，如果匹配到argv[1],就打印，最后输出匹配的条数
        while( getlineA(line, MAXLINE) > 0 ){
            if(strstr(line, argv[1]) != NULL ){
                printf("%s ", line);
                found++;
            }
        }
    }
    printf("匹配到的行数为： %d \n", found);
    return found;
}

/* 这个方法不断从标准输入读取内容，放到char array 中 */
int getlineA(char s[], int lim){

    int c, i;
    i = 0;
    while( --lim > 0 && (c = getchar()) != EOF && c!= '\n'){
        s[i++] = c; 
    }
    if(c == '\n'){
        s[i++] = c; 
    }
    s[i] = '\0';
    return i;
}


