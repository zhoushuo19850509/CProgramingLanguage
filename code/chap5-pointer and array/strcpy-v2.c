#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcpyv2(char *s, char *t);

/**
 * 功能： 字符串拷贝
 * 目标： 为了说明如何通过指针移动实现字符串拷贝
 */
int main(){
    
    char *t = "hello world!\0";
    char *s = malloc( strlen(t) * sizeof(char));
    strcpyv2(s, t);
    printf("%s \n", s);

}

// 字符串拷贝 t ->
void strcpyv2(char *s, char *t){
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}