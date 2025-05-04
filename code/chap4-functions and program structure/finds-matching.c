#include <stdio.h>
#define MAXLINE 1000

int mygetline(char s[], int lim);
int strindex(char s[], char t[]);

// 要匹配的关键字
char pattern[] = "return";

/**
 * 功能： 字符串匹配
 * 目标： 为了说明function的用法
*/
int main(){
    printf("start matching ...\n");

    char line[MAXLINE];
    int found = 0;
    while(mygetline(line, MAXLINE) > 0){
        if( strindex(line, pattern) > 0){
            printf("%s",line);
            found++;
        }
    }
    printf("finish get all lines ...\n");
    printf("pattern count:  %d \n" , found);
}

/* 这个方法不断从标准输入读取内容，放到char array 中 */
int mygetline(char s[], int lim){

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

/* 从字符串s中查找是否有字符串t ，如果有的话，就返回t 在s中的index */
int strindex(char s[], char t[]){
    // i 用于遍历s
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++){
        for(j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++,k++){
            ; // do nothing ..
        }
        if(k > 0 && t[k] == '\0'){
            return i;
        }
    }
    return -1;
}


