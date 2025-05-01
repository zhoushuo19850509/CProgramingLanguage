#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(){
    char a[11];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'c';
    a[3] = 'd';
    a[4] = 'e';
    a[5] = 'f';
    a[6] = 'g';
    a[7] = 'h';
    a[8] = 'i';
    a[9] = 'j';
    a[10] = '\0';
    reverse(a);

    int i;
    for(i = 0; i < 10; i++){
        printf("a[%d] : %c \n" ,i, a[i]);
    } 
}

void reverse(char s[]){
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j-- ){
        printf("i:%d and j:%d \n", i, j);
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
