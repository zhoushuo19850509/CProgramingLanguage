#include <stdio.h>

int lower(int c);

/**
 * 大写改小写：
 * A -> a
*/
int main(){

    // 随便试一个
    int a = 'A';
    a = lower(a);
    printf("lower result : : %c \n", a);

    // 把所有大写字母都转换一遍
    int origin ;
    int lowered ;
    for(origin = 'A'; origin <= 'Z'; origin++){
        lowered = lower(origin);
        printf("origin: %c  -> lowered:  %c \n", origin, lowered);
    }

}

/**
 * 大写改小写：
 * A -> a
*/
int lower(int c){

    if(c >= 'A' && c <= 'Z'){
        c = c + ( 'a' - 'A');
    }
    return c;
}

