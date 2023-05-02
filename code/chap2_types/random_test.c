#include <stdio.h>

int next;
int randGenerate(void);
void setSeed(unsigned int seed);

/**
 * 测试生成随机数的场景
*/
int main(){
    
    int count;
    int i;
    setSeed(47);
    int rand;
    count = 10;
    for(i = 0 ; i < count; i++){
        rand = randGenerate();
        printf("random: %d \n", rand);
    }
}

/**
 * 创建一个(伪)随机数： 0 - 32768
*/
int randGenerate(void){
    next = next * 1103515245 + 12345;
    return (unsigned int) next / 65536 % 32768;
}

/**
 * 设置随机数种子
*/
void setSeed(unsigned int seed){
    next = seed;
}

