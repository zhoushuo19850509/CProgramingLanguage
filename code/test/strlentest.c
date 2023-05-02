#include <stdio.h>
#include <string.h>

int main(){
    char str[10];
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = 'd';
    str[4] = 'e';
    str[5] = '\0';

    int a = strlen(str);
    printf("sting length: %d \n", a);

}