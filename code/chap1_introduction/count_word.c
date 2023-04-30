#include <stdio.h>

#define OUT 0
#define IN 1

/**
 * 统计行数(nl)、word数(wc)、char数(nc)
*/
int main(){
    int nl, nw, nc;
    int c;
    int state;
    state = OUT;
    nl = nw = nc = 0;

    while( (c = getchar()) != EOF){
        nc++;

        if(c == '\n'){
            nl++;
        }
        
        /**
         * 如果读取到' '/'\n'/'\t'，
         * 就说明找到了word的分隔符
         * 重置一下状态： state = OUT
         */
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        }else if(state == OUT){
            state = IN;
            nw++;
        }
    }

    printf("print total char count : %d \n",nc);
    printf("print total line count : %d \n",nl);
    printf("print total word count : %d \n",nw);
}