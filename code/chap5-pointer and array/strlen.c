#include <stdio.h>

/**
 * 功能：计算string长度
 * 目标：为了说明指针和数组的关系
 */
int strlen(char *s);
int main(){
    char *s = "hello\0";
    int n = strlen(s);
    printf("%d \n", n);
}

int strlen(char *s){
    int n;

    for(n = 0; *s != '\0'; s++){
        n++;
    }
    return n;

}