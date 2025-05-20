#include <stdio.h>
#include <time.h>

/**
 * 功能： 计算时间耗时
 * 目标： 介绍如何通过time.h提供的时间函数，计算时间耗时
 * 
 * 时间换算：
 * 1秒 = 1000毫秒
 * 1毫秒 = 1000微秒
*/
int main(){
    printf("start time test ... \n");

    clock_t start;
    clock_t end;

    start = clock();

    int i;
    int sum = 0;
    for(i = 0; i < 1000 ; i++){
        sum += i * i * i;
    }
    printf("sum: %d \n", sum);
    end = clock();

    // 默认是 精确到微秒 比如6微秒
    printf("time cost: %f in us \n", 
    (double)(end - start) );

    // 默认是 精确到微秒 比如0.006毫秒
    printf("time cost: %f in ms \n", 
    (double)(end - start)/1000 );

    // 精确到秒， 比如： 0.000006
    printf("time cost: %f in sec\n", 
    (double)(end - start) / CLOCKS_PER_SEC);

    
    
}