#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * 功能：造一个随机的自然数n( 50 > n >=0 )
 * 目标：为了说明如何调用stdlib.h提供rand()函数，造随机数
 * 备注：
 */
int main(){    
    int i;
    int random_value;

    time_t t;
    /**
     * 设置seed
     * 为了避免伪随机数，我们这里拿时间作为seed
     */
    unsigned int time_seed = (unsigned)time(&t);
    printf("time_seed: %d \n", time_seed);
    srand(time_seed);

    /**
     * 打印随机数
     */
    for(i = 0; i < 100; i++){
        random_value = rand() % 50;
        printf("print random value: %d \n", random_value);
    }

}
