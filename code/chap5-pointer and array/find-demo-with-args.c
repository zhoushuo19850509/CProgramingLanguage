#include <stdio.h>
#include <string.h>

int getlineA(char s[], int lim);
#define MAXLINE 1000

/**
 * 功能： 模拟find命令： find -x -n aaa xxx
      备注： 功能和find-demo.c类似，就是打印、统计匹配关键字的行
      不同的是，支持参数，
      -x 是反向匹配的意思 比如原来匹配的就不匹配了，原来不匹配的现在匹配了
      -n 意思是打印匹配的行号
 * 目标： 1.为了说明main argument的用法
         2.为了介绍linux shell命令的解释过程
 */
int main(int argc, char *argv[]){

    printf("argc: %d and argv: %s \n", argc, argv[0]);

    char line[MAXLINE];
    int found = 0; 
    int c;
    int exception = 0; // 默认关闭exception
    int number = 0;    // 默认关闭number
    int lineno = 0; // 展示行号
    // 先解析命令的参数 -x -n
    while(--argc > 0 && (*++argv)[0] == '-'){
        while( c = (*++argv[0])){
            switch(c){
                case 'x':
                    exception = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    // 参数格式错误
                    printf("illegal optional: %c \n",c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    printf("finish dealing optional...\n");
    // 判断命令的用法是否合法
    if(argc != 1){ // 经过上述处理，正常状态下argc应该是1
        printf("Usage: finds pattern \n");
    }else{
        // 不断读取标准输入内容，如果匹配到argv[1],就打印，最后输出匹配的条数
        while( getlineA(line, MAXLINE) > 0 ){
            if( (strstr(line, *argv) != NULL) != exception ){
                if(number){
                    lineno++;
                    printf("%1d:", lineno);
                }
                printf("%s", line);
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


