#include <stdio.h>

#define MAXLINE 1000

int getlineA(char line[], int lim);
void copy(char to[], char from[]);

/**
 * 这个代码主要是为了说明char array的用法
 * 关注点是，从C语言中，string的定义是这样的：
 * 一串char array，以'\n\0'结尾
 * 其中'\n'代表回车， \0代表一行的末尾
 * 这时C语言中约定俗成的，对string的定义
*/
int main(){

    char line[MAXLINE];
    
    int max = 0; // 记录最长的char array中，有多少char
    char maxline[MAXLINE];  // 记录最长的行
    int len;
    while( (len = getlineA(line, MAXLINE)) > 0){
        if( len >  max){
            copy(maxline, line);
            max = len;
            // printf("current longest char array size: %d \n", max);
        }
    }
    printf("print longest char array: %s \n",maxline);
    printf("size of the longest char array: %d \n",max);
}

/**
 * 读取标准输入，放到 char array
 * @param line  把从标准输入读取的内容，放到这个char array中
 * @param lim  char array最长的长度
 * @return 返回读取到的这行char array的长度
*/
int getlineA(char line[], int lim){
    int i;
    int c;

    for(i = 0 ; i < lim && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';  // 每行都以'\n\0'结尾
    return i;
}

/**
 * char array copy ...
*/
void copy(char to[], char from[]){
    int i = 0;

    while( (to[i] = from[i]) != '\0'){
        i++;
    }
}





