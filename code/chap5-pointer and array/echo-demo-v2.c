#include <stdio.h>

/**
 * 功能： 实现类似echo的功能
 * 目标： 为了说明main argument的用法(遍历指针法)
 */
int main(int argc, char *argv[]){

    // printf("argc: %d and argv: %s \n", argc, argv[0]);
    while(--argc > 0){
        printf("%s ", *++argv);
    }
    printf("\n");
    return 0;
}


