#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcpyv1(char *s, char *t);

/**
 * 功能： 字符串拷贝
 * 目标： 为了说明如何通过数组实现字符串拷贝
 */
int main(){
    
    char *t = "hello world!\0";
    char *s = malloc( strlen(t) * sizeof(char));
    strcpyv1(s, t);
    printf("%s \n", s);

}

// 字符串拷贝 t ->
void strcpyv1(char *s, char *t){
    int i;
    i = 0;
    while((s[i] = t[i]) != '\0'){
        i++;
    }
}