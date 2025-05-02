#include <stdio.h>
#include <string.h>

int main(){
    char *s = "hello\0";
    char *t = "hello\0";
    int n = strcmp(s, t);
    printf("%d\n", n);
}