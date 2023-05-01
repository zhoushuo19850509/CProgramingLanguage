#include <stdio.h>

#define MAXLINE 1000

int max; // 记录最长的char array中，有多少char
char maxline[MAXLINE];  // 记录最长的行
char line[MAXLINE];

int getlineA(void);
void copy(void);

/**
 * 这个代码和print_longest_line.c功能类似
 * 主要是为了说明extern variable的用法
 * 
*/
int main(){

    extern int max;
    extern char maxline[];
    
    max = 0;
    int len;
    while( (len = getlineA()) > 0){
        if( len >  max){
            copy();
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
int getlineA(void){
    int i;
    int c;

    extern char line[];

    for(i = 0 ; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; i++){
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
void copy(){
    int i = 0;

    extern char maxline[];  // 记录最长的行
    extern char line[]; // 记录当前读取的行

    while( (maxline[i] = line[i]) != '\0'){
        i++;
    }
}





