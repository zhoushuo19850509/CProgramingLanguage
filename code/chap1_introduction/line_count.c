#include <stdio.h>

/**
 * count the number of lines ...
*/
int main(){
    int nl;
    nl = 0;
    int c;

    while( (c = getchar()) != EOF){
        if(c == '\n'){
            nl++;
        }
    }
    printf("print line count : %d \n", nl);
}