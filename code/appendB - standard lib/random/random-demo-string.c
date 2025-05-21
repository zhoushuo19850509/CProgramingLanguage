#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// [a-zA-Z]
char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *randomString(int n);

/**
 * 功能：造一个长度为n的随机字符串(字符串包含: [a-zA-Z])
 * 目标：为了说明如何调用stdlib.h提供rand()函数，造随机数
 */
int main(){
    
    /**
     * 设置seed
     * 为了避免伪随机数，我们这里拿时间作为seed
     * 备注：这个步骤不能放在 randomString()函数内部
     * 否则的话，如果在短时间内循环调用randomString()，
     * 就会生成重复的字符串
     */
    time_t t;
    unsigned int time_seed = (unsigned)time(&t);
    printf("time_seed: %d \n", time_seed);
    srand(time_seed);

    int i;
    char *a;
    for(i = 0; i < 100; i++){
        a = randomString(10);
        printf("string of a: %s \n", a);
    }


}

/**
 * 返回长度为n的随机字符串
 */
char *randomString(int n){
    // 创建一个长度为n的字符串
    char *result = malloc(n * sizeof(char));
    /**
     * 然后循环调用rand(),生成一个0-51之间的一个随机数
     * 这个随机数从[a-zA-Z]52个字符中随机挑选一个字符
     */
    int index ;
    int i;
    for(i = 0; i < n; i++){
        index = alpha_rand();
        result[i] = alpha[index];
    }
    return result;

}

