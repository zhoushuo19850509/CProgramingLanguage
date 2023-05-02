#include <stdio.h>

void squeeze(char s[], int c);
/**
 * 从一个char array中剔除某个特定的char
*/
int main(){
    char str[10];
    str[0] = '2';
    str[1] = '3';
    str[2] = '1';
    str[3] = '0';
    str[4] = '5';
    str[5] = '1';
    str[6] = '3';
    str[7] = '3';
    str[8] = '\0';

    squeeze(str, '3');
    printf("%s \n", str);
}

void squeeze(char s[], int c){
    int i,j;
    j = 0;
    for(i = 0 ; s[i] != '\0' ;i++){
        if(s[i] != c){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

