#include <stdio.h>

void swap(int *px, int *py);

/**
 * 功能： 交换两个int类型的变量
   目标： 为了说明指针作为函数参数的场景
*/
int main(){
    int a = 1;
    int b = 5;
    swap(&a, &b);
    printf("a: %d, b: %d \n", a, b);

}

void swap(int *px, int *py){
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}
