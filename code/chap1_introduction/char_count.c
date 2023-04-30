#include <stdio.h>

/**
 * count the number of chars ...
 * // 场景1 char count 为5 (其中\n占据一个char)
 * hello\n   
 * 
 * // 场景2 char count 为9(其中2个\n占据2个char)
 * hello\n
 * hi\n
 * 
*/
int main(){
    int nc;
    nc = 0;

    while( getchar() != EOF){
        nc++;
    }
    printf("print total char count : %d \n",nc);
}