#include <stdio.h>

int atoi(char a[]);

/**
 * version1.0 of atoi()
 * transfer char array to int: 
 * '123\0' -> 123
*/
int main(){
    char str[10];
    str[0] = '2';
    str[1] = '3';
    str[2] = '1';
    str[3] = '0';
    str[4] = '5';
    str[5] = '\0';

    int a = atoi(str);
    printf("atoi result : : %d \n", a);

}

int atoi(char a[]){
    int i, n;
    n = 0;
    for(i = 0 ; a[i] >= '0' && a[i]<= '9' ; i++){
        n = n * 10 + (a[i] - '0');
    }
    return n;
}

