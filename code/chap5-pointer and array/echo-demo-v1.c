#include <stdio.h>

/**
 * 功能： 实现类似echo的功能
 * 目标： 为了说明main argument的用法(数组法)
 */
int main(int argc, char *argv[]){

    // printf("argc: %d and argv: %s \n", argc, argv[0]);
    int i;
    for(i = 1; i < argc; i++){
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}


