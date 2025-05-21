#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 功能：造一个随机的浮点数f（ 1 > f > 0）
 * 目标：为了说明如何调用stdlib.h提供rand()函数，造随机数
 * 备注：这个浮点数是伪随机数
 */
int main(){
    
    int i;

    printf("RAND_MAX: %d \n ", RAND_MAX);

    /**
     * 设置seed
     * 为了避免伪随机数，我们这里拿时间作为seed
     */
    time_t t;
    unsigned int time_seed = (unsigned)time(&t);
    printf("time_seed: %d \n", time_seed);
    srand(time_seed);
    
    double random_value_f;
    for(i = 0; i < 100; i++){
        random_value_f = ((double) rand()) /(RAND_MAX + 1.0);
        printf("print random value: %f \n", random_value_f);
    }


}
