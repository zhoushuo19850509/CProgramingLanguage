#include <stdio.h>

/*这个代码统计标准输入的各个字符数量，用于说明switch的用法 */
int main(){
    /* nwhite 记录空格/回车/tag 
       ndigit 记录数字
       nother 记录其他字符
    */
    int c, nwhite, nother, ndigit[10];

    // 初始化
    nwhite = nother = 0;
    int i;
    for(i = 0; i < 10; i++){
        ndigit[i] = 0;
    }

    while( (c = getchar()) != EOF){
        switch(c){
            case '0': case '1': case '2': case '3': case '4': 
            case '5': case '6': case '7': case '8': case '9':
              ndigit[c - '0']++;
              break;
            case ' ':  
            case '\n':  
            case '\t':
              nwhite++;
              break;
            default:
              nother++;
              break;  
        }
    }

    /*打印统计结果 */
    for(i = 0; i < 10; i++){
        printf("%d : %d \n" , i, ndigit[i]);
    }
    printf("count white: %d and others: %d", nwhite, nother);
}