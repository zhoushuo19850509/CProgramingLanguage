#include <stdio.h>

int main(){

}

#define ALLOCSIZE 10000 // 最大能够申请的内存

static char allocbuf[ALLOCSIZE]; // 存放内存的基础数据结构： 数组
static char *allocp = allocbuf;  // 这个指针指向下一个可用的内存地址

char *alloc(int n){
    // 可用内存空间符合申请要求
    if( allocbuf + ALLOCSIZE - allocp > n){
        // 移动一下指针地址，说明本次内存申请生效了
        allocp = allocp + n;
        return allocp - n; // 返回本次申请的可用的内存地址
    }else{
        printf("not enough memory space!");
        return 0;
    }
}

void afree(char *p){
    if(p >= allocbuf && a < allocbuf + ALLOCSIZE){
        allocp = p;
    }
}


