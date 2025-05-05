#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 // 每行最大的长度

int getlineA(char *line, int max);

/**
 * 功能： 就是实现getline()函数
 * 目标： 为了说明fgetc()函数在getline()方法中的作用，
 *       啥意思呢？C标准库中，fgetc()能够逐行读取文件内容
 *       这就避免了我们之前实现的getline()，从stdin逐个字符读取
 *       备注：虽然fgetc()内部实现也是逐个字符从stdion读取的
 */
int main(){
    int n;
    char line[MAXLINE];

    while( (n = getlineA(line, MAXLINE)) > 0){
        printf("%s \n", line);
    }
    printf("finish reading lines ...\n");
}

int getlineA(char *line, int max){

    if(fgets(line, max, stdin) == NULL){
        return 0;  // 读取到异常（比如ctl+C）
    }else{
        return strlen(line);
    }

}
