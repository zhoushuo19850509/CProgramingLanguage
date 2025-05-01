#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char a[]);

/**
 * itoa() 数字转字符串
 * 用来说明do{}while(); 的用法
 */
int main(){
    int n = -123;
    char a[5];
    itoa(n, a);
    printf("%s \n", a);
}

/**
 * 数字转字符串(字符串以'\0'结尾)
 */
void itoa(int n, char a[]){
    int i , sign;

    i = 0;
    sign = n;
    // 先取n的绝对值
    if(n < 0){
        n = -n;
    }

    do{
        a[i++] = n % 10 + '0';
    }while( (n = n / 10) > 0);
    if( sign < 0){
        a[i++] = '-';
    }
    a[i] = '\0';
    reverse(a);
}
void reverse(char s[]){
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j-- ){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

