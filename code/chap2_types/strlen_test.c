#include <stdio.h>


int strlenA(char a[]);

/**
 * version1.0 of strlen()
 * 统计char array的长度
 * (关键点是，在C语言中，string以char array为代表，以'\0'结尾)
*/
int main(){
    char str[10];
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = 'd';
    str[4] = 'e';
    str[5] = '\0';

    int a = strlenA(str);
    printf("sting length: %d \n", a);

}

int strlenA(char a[]){
    int i;
    i = 0;
    while(a[i] != '\0'){
        i++;
    }
    return i;
}
